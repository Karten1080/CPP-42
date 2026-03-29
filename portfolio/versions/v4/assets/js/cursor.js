/* ============================================================
   V4 — cursor.js · Curseur magnétique + spotlight hero
   ============================================================ */
(function () {
  'use strict';

  var dot  = document.getElementById('cursor-dot');
  var ring = document.getElementById('cursor-ring');
  if (!dot) return;

  var mx = 0, my = 0;
  var rx = 0, ry = 0;
  var rafId;

  /* ---- Suivi de la souris ---- */
  document.addEventListener('mousemove', function (e) {
    mx = e.clientX;
    my = e.clientY;
    dot.style.left = mx + 'px';
    dot.style.top  = my + 'px';
  }, { passive: true });

  /* ---- Anneau avec lag ---- */
  function lerp(a, b, t) { return a + (b - a) * t; }

  function animateRing() {
    rx = lerp(rx, mx, 0.11);
    ry = lerp(ry, my, 0.11);
    ring.style.left = rx + 'px';
    ring.style.top  = ry + 'px';
    rafId = requestAnimationFrame(animateRing);
  }
  animateRing();

  /* ---- Cacher / afficher ---- */
  document.addEventListener('mouseleave', function () {
    dot.style.opacity  = '0';
    ring.style.opacity = '0';
  });
  document.addEventListener('mouseenter', function () {
    dot.style.opacity  = '1';
    ring.style.opacity = '1';
  });

  /* ---- États hover / click ---- */
  var interactives = 'a, button, .card, .badge, .track-btn, .track-dot, .filter-btn, .tag, .writeup-link';

  function addHover(el) {
    el.addEventListener('mouseenter', function () { document.body.classList.add('cursor-hover'); });
    el.addEventListener('mouseleave', function () { document.body.classList.remove('cursor-hover'); });
  }

  document.querySelectorAll(interactives).forEach(addHover);

  // Observer pour les éléments ajoutés dynamiquement
  var mo = new MutationObserver(function (mutations) {
    mutations.forEach(function (m) {
      m.addedNodes.forEach(function (node) {
        if (node.nodeType === 1) {
          if (node.matches && node.matches(interactives)) addHover(node);
          node.querySelectorAll && node.querySelectorAll(interactives).forEach(addHover);
        }
      });
    });
  });
  mo.observe(document.body, { childList: true, subtree: true });

  document.addEventListener('mousedown', function () { document.body.classList.add('cursor-click'); });
  document.addEventListener('mouseup',   function () { document.body.classList.remove('cursor-click'); });

  /* ---- Magnetic effect on .btn-magnetic ---- */
  document.querySelectorAll('.btn-magnetic').forEach(function (btn) {
    btn.addEventListener('mousemove', function (e) {
      var rect = btn.getBoundingClientRect();
      var x = e.clientX - rect.left - rect.width  / 2;
      var y = e.clientY - rect.top  - rect.height / 2;
      btn.style.transition = 'transform 0ms';
      btn.style.transform  = 'translate(' + (x * 0.28) + 'px, ' + (y * 0.28) + 'px)';
    });
    btn.addEventListener('mouseleave', function () {
      btn.style.transition = 'transform 500ms cubic-bezier(0.25,0.46,0.45,0.94)';
      btn.style.transform  = 'translate(0, 0)';
    });
  });

  /* ---- Hero spotlight ---- */
  var hero = document.getElementById('hero');
  if (hero) {
    document.addEventListener('mousemove', function (e) {
      var rect = hero.getBoundingClientRect();
      if (e.clientY < rect.top || e.clientY > rect.bottom) return;
      hero.style.setProperty('--mx', (e.clientX - rect.left) + 'px');
      hero.style.setProperty('--my', (e.clientY - rect.top)  + 'px');
    }, { passive: true });
  }
})();
