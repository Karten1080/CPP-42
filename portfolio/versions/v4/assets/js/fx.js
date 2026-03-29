/* ============================================================
   V4 — fx.js · Loader, Terminal, Tilt 3D, Scramble, Track, Counter, Copy
   ============================================================ */
(function () {
  'use strict';

  /* ================================================================
     LOADER
  ================================================================ */
  function initLoader() {
    var loader   = document.getElementById('loader');
    var fill     = document.getElementById('loader-bar-fill');
    var linesEl  = document.getElementById('loader-lines');
    if (!loader || !linesEl) { document.body.classList.add('loaded'); return; }

    var steps = [
      { text: '> LOADING SECURITY PROFILE...', delay: 0 },
      { text: '> CHECKING CTF CREDENTIALS...', delay: 420 },
      { text: '> SCANNING FOR VULNERABILITIES...', delay: 820 },
      { text: '> ACCESS GRANTED', delay: 1200, ok: true },
    ];

    // Progress bar
    setTimeout(function () { if (fill) fill.style.width = '100%'; }, 50);

    steps.forEach(function (step) {
      setTimeout(function () {
        // Mark previous lines as done
        linesEl.querySelectorAll('.line.active').forEach(function (l) {
          l.classList.remove('active');
          if (!step.ok) l.classList.add('ok');
        });
        var line = document.createElement('div');
        line.className = 'line ' + (step.ok ? 'ok' : 'active');
        line.textContent = step.text;
        linesEl.appendChild(line);
      }, step.delay);
    });

    // Fade out loader
    setTimeout(function () {
      loader.classList.add('out');
      setTimeout(function () {
        loader.style.display = 'none';
        document.body.classList.add('loaded');
      }, 650);
    }, 1750);
  }

  /* ================================================================
     TERMINAL
  ================================================================ */
  function initTerminal() {
    var body = document.getElementById('terminal-body');
    if (!body) return;

    var lines = [
      { type: 'cmd',  text: 'whoami' },
      { type: 'out',  text: 'adel-smati  ·  École 42 Paris', cls: 'ok' },
      { type: 'cmd',  text: 'cat /etc/stage.conf' },
      { type: 'out',  text: 'ROLE=Pentest|SOC  DURATION=6mois  START=2026-05' },
      { type: 'cmd',  text: 'nmap --open -sV adel-smati.github.io' },
      { type: 'out',  text: 'PORT     STATE  SERVICE', cls: 'warn' },
      { type: 'out',  text: '443/tcp  open   pentest-stage-mai-2026', cls: 'ok' },
      { type: 'cmd',  text: '' },
    ];

    var CURSOR_HTML = '<span class="cur"></span>';
    var i = 0;

    // Wait for loader to finish
    var startDelay = 2000;

    function appendLine(line, cb) {
      if (line.type === 'cmd') {
        var p = document.createElement('p');
        p.innerHTML = '<span class="prompt">┌─[as@42]─$ </span><span class="cmd"></span>' + CURSOR_HTML;
        body.appendChild(p);
        var cmdEl = p.querySelector('.cmd');
        var cur   = p.querySelector('.cur');

        if (!line.text) { if (cb) setTimeout(cb, 200); return; }

        var j = 0;
        var t = setInterval(function () {
          cmdEl.textContent += line.text[j++];
          if (j >= line.text.length) {
            clearInterval(t);
            cur.remove();
            if (cb) setTimeout(cb, 180);
          }
        }, 45 + Math.random() * 30);

      } else {
        var out = document.createElement('p');
        out.className = 'out ' + (line.cls || '');
        out.textContent = line.text;
        body.appendChild(out);
        if (cb) setTimeout(cb, 120);
      }
      // Auto-scroll
      body.scrollTop = body.scrollHeight;
    }

    function nextLine() {
      if (i >= lines.length) return;
      appendLine(lines[i++], nextLine);
    }

    setTimeout(function () {
      var term = document.getElementById('terminal');
      if (term) term.classList.add('visible');
      nextLine();
    }, startDelay);
  }

  /* ================================================================
     TILT 3D (sur les .tilt-card)
  ================================================================ */
  function initTilt() {
    document.querySelectorAll('.tilt-card').forEach(function (card) {
      card.addEventListener('mousemove', function (e) {
        var rect = card.getBoundingClientRect();
        var x = (e.clientX - rect.left) / rect.width  - 0.5;
        var y = (e.clientY - rect.top)  / rect.height - 0.5;
        card.style.transition = 'border-color 200ms, box-shadow 200ms, transform 0ms';
        card.style.transform  =
          'perspective(700px) rotateX(' + (-y * 9) + 'deg) rotateY(' + (x * 9) + 'deg) translateZ(6px)';
      });
      card.addEventListener('mouseleave', function () {
        card.style.transition = 'border-color 200ms, box-shadow 200ms, transform 500ms ease';
        card.style.transform  = 'perspective(700px) rotateX(0) rotateY(0) translateZ(0)';
      });
    });
  }

  /* ================================================================
     TEXT SCRAMBLE
  ================================================================ */
  var SCRAMBLE_CHARS = 'ABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789@#$%&!?<>';

  function scramble(el, finalText, duration) {
    if (!el) return;
    el.dataset.scramble = 'true';
    var total = Math.ceil(duration / 28);
    var iter  = 0;

    var iv = setInterval(function () {
      var progress = iter / total;
      el.textContent = finalText
        .split('')
        .map(function (ch, idx) {
          if (ch === ' ') return ' ';
          if (idx < progress * finalText.length) return ch;
          return SCRAMBLE_CHARS[Math.floor(Math.random() * SCRAMBLE_CHARS.length)];
        })
        .join('');

      if (iter >= total) {
        el.textContent   = finalText;
        el.dataset.scramble = 'done';
        clearInterval(iv);
      }
      iter++;
    }, 28);
  }

  function initScramble() {
    var els = document.querySelectorAll('[data-final]');
    if (!els.length) return;

    var obs = new IntersectionObserver(function (entries) {
      entries.forEach(function (e) {
        if (e.isIntersecting) {
          var el = e.target;
          scramble(el, el.dataset.final, 900);
          obs.unobserve(el);
        }
      });
    }, { threshold: 0.3 });

    els.forEach(function (el) { obs.observe(el); });
  }

  /* ================================================================
     HORIZONTAL SCROLL — PROJECTS TRACK
  ================================================================ */
  function initTrack() {
    var track   = document.getElementById('projects-track');
    var btnPrev = document.getElementById('track-prev');
    var btnNext = document.getElementById('track-next');
    var dotsEl  = document.getElementById('track-dots');
    if (!track) return;

    var slides = track.querySelectorAll('.project-slide');
    var total  = slides.length;
    var cur    = 0;

    // Build dots
    if (dotsEl) {
      slides.forEach(function (_, i) {
        var d = document.createElement('button');
        d.className = 'track-dot' + (i === 0 ? ' active' : '');
        d.setAttribute('aria-label', 'Projet ' + (i + 1));
        d.addEventListener('click', function () { goTo(i); });
        dotsEl.appendChild(d);
      });
    }

    function slideWidth() {
      return slides[0].offsetWidth + parseInt(getComputedStyle(track).gap || '20');
    }

    function goTo(idx) {
      cur = Math.max(0, Math.min(idx, total - 1));
      track.style.transform = 'translateX(' + (-cur * slideWidth()) + 'px)';

      if (btnPrev) btnPrev.disabled = cur === 0;
      if (btnNext) btnNext.disabled = cur >= total - 2;

      if (dotsEl) {
        dotsEl.querySelectorAll('.track-dot').forEach(function (d, i) {
          d.classList.toggle('active', i === cur);
        });
      }
    }

    if (btnPrev) btnPrev.addEventListener('click', function () { goTo(cur - 1); });
    if (btnNext) btnNext.addEventListener('click', function () { goTo(cur + 1); });

    // Touch swipe
    var touchStartX = 0;
    track.addEventListener('touchstart', function (e) { touchStartX = e.touches[0].clientX; }, { passive: true });
    track.addEventListener('touchend', function (e) {
      var diff = touchStartX - e.changedTouches[0].clientX;
      if (diff > 50)  goTo(cur + 1);
      if (diff < -50) goTo(cur - 1);
    });

    goTo(0);
    window.addEventListener('resize', function () { goTo(cur); });
  }

  /* ================================================================
     COUNTER ANIMATION
  ================================================================ */
  function initCounters() {
    var els = document.querySelectorAll('[data-count]');
    if (!els.length) return;

    var obs = new IntersectionObserver(function (entries) {
      entries.forEach(function (e) {
        if (!e.isIntersecting) return;
        var el     = e.target;
        var target = parseInt(el.dataset.count);
        var suffix = el.dataset.suffix || '';
        var dur    = 1000;
        var start  = performance.now();

        function tick(now) {
          var p   = Math.min((now - start) / dur, 1);
          var val = Math.round(p * target);
          el.textContent = val + suffix;
          if (p < 1) requestAnimationFrame(tick);
        }
        requestAnimationFrame(tick);
        obs.unobserve(el);
      });
    }, { threshold: 0.6 });

    els.forEach(function (el) { obs.observe(el); });
  }

  /* ================================================================
     COPY EMAIL
  ================================================================ */
  function initCopyEmail() {
    var link = document.getElementById('copy-email');
    var fb   = document.getElementById('copy-feedback');
    if (!link || !fb) return;

    link.addEventListener('click', function (e) {
      e.preventDefault();
      navigator.clipboard.writeText('adel.smati@gmail.com').then(function () {
        fb.textContent = '✓ EMAIL COPIÉ DANS LE PRESSE-PAPIER';
        fb.classList.add('ok');
        setTimeout(function () { fb.textContent = ''; fb.classList.remove('ok'); }, 2500);
      }).catch(function () {
        window.location.href = 'mailto:adel.smati@gmail.com';
      });
    });
  }

  /* ================================================================
     INIT
  ================================================================ */
  function init() {
    initLoader();
    initTerminal();
    initTilt();
    initScramble();
    initTrack();
    initCounters();
    initCopyEmail();
  }

  if (document.readyState === 'loading') {
    document.addEventListener('DOMContentLoaded', init);
  } else {
    init();
  }
})();
