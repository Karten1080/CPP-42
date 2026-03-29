/* ============================================================
   V4 — matrix.js · ASCII Matrix Rain + security terms
   ============================================================ */
(function () {
  'use strict';

  var canvas = document.getElementById('matrix-canvas');
  if (!canvas) return;

  var ctx = canvas.getContext('2d');
  var W, H, cols, drops, secWords, wordMap;

  var KATAKANA = 'アイウエオカキクケコサシスセソタチツテトナニヌネノハヒフヘホマミムメモヤユヨラリルレロワヲン';
  var HEX = '0123456789ABCDEF';
  var CHARS = KATAKANA + HEX + '01!@#$';
  var SECURITY_TERMS = ['CVE','ROOT','SHELL','PWN','XSS','SQLi','SSRF','0x41','NMAP','GDB','RCE','AUTH'];

  var FONT_SIZE = 13;

  function init() {
    var hero = canvas.parentElement;
    W = canvas.width  = hero ? hero.offsetWidth  : window.innerWidth;
    H = canvas.height = hero ? hero.offsetHeight : window.innerHeight;
    cols  = Math.floor(W / FONT_SIZE);
    drops = [];
    secWords = [];
    wordMap = {};

    for (var i = 0; i < cols; i++) {
      drops[i] = Math.random() * -80;
    }

    // Assign some columns to carry security terms
    var termCount = Math.floor(cols / 10);
    for (var t = 0; t < termCount; t++) {
      var col = Math.floor(Math.random() * cols);
      var word = SECURITY_TERMS[Math.floor(Math.random() * SECURITY_TERMS.length)];
      wordMap[col] = { word: word, pos: 0 };
    }
  }

  function draw() {
    // Fade trail
    ctx.fillStyle = 'rgba(3,6,9,0.05)';
    ctx.fillRect(0, 0, W, H);

    ctx.font = FONT_SIZE + 'px JetBrains Mono, monospace';

    for (var i = 0; i < drops.length; i++) {
      var y = drops[i] * FONT_SIZE;

      var ch;
      if (wordMap[i] && drops[i] > 0) {
        // Leading char bright, word chars below
        var wm = wordMap[i];
        var relPos = Math.floor(drops[i]) - Math.floor(drops[i] - wm.word.length);
        if (relPos >= 0 && relPos < wm.word.length) {
          ch = wm.word[relPos];
        } else {
          ch = CHARS[Math.floor(Math.random() * CHARS.length)];
        }
      } else {
        ch = CHARS[Math.floor(Math.random() * CHARS.length)];
      }

      // Leading character — bright neon
      ctx.fillStyle = '#00ff88';
      ctx.fillText(ch, i * FONT_SIZE, y);

      // Occasional dim character above for trail effect
      if (drops[i] > 3) {
        ctx.fillStyle = 'rgba(0,180,80,0.3)';
        ctx.fillText(
          CHARS[Math.floor(Math.random() * CHARS.length)],
          i * FONT_SIZE,
          (drops[i] - 2) * FONT_SIZE
        );
      }

      // Reset column when it goes off screen
      if (y > H && Math.random() > 0.975) {
        drops[i] = 0;
        // Occasionally reassign security word
        if (Math.random() > 0.7) {
          wordMap[i] = {
            word: SECURITY_TERMS[Math.floor(Math.random() * SECURITY_TERMS.length)],
            pos: 0
          };
        }
      }

      drops[i] += 0.45;
    }
  }

  init();

  var raf;
  function loop() { draw(); raf = requestAnimationFrame(loop); }
  loop();

  var resizeTimer;
  window.addEventListener('resize', function () {
    clearTimeout(resizeTimer);
    resizeTimer = setTimeout(function () {
      cancelAnimationFrame(raf);
      init();
      loop();
    }, 200);
  });
})();
