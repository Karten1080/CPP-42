/* V2 — main.js */
(function () {
  'use strict';

  /* CURSOR */
  function initCursor() {
    const dot = document.getElementById('cursor');
    const ring = document.getElementById('cursor-ring');
    if (!dot) return;
    let rx = 0, ry = 0, dx = 0, dy = 0;

    document.addEventListener('mousemove', function(e) {
      dx = e.clientX; dy = e.clientY;
      dot.style.left = dx + 'px'; dot.style.top = dy + 'px';
    }, { passive: true });

    if (ring) {
      (function loop() {
        rx += (dx - rx) * 0.12; ry += (dy - ry) * 0.12;
        ring.style.left = rx + 'px'; ring.style.top = ry + 'px';
        requestAnimationFrame(loop);
      })();
    }

    document.addEventListener('mouseleave', function() {
      dot.style.opacity = '0';
      if (ring) ring.style.opacity = '0';
    });
    document.addEventListener('mouseenter', function() {
      dot.style.opacity = '1';
      if (ring) ring.style.opacity = '1';
    });

    document.querySelectorAll('a, button, .card, .badge, .filter-btn').forEach(function(el) {
      el.addEventListener('mouseenter', function() { document.body.classList.add('cursor-hover'); });
      el.addEventListener('mouseleave', function() { document.body.classList.remove('cursor-hover'); });
    });
  }

  /* TYPEWRITER */
  function initTypewriter() {
    var el = document.getElementById('hero-name');
    if (!el) return;
    var text = el.dataset.text || el.textContent.trim();
    el.textContent = '';
    var cur = document.createElement('span');
    cur.className = 'cursor-type'; cur.setAttribute('aria-hidden', 'true');
    el.appendChild(cur);
    var i = 0;
    function type() {
      if (i < text.length) {
        el.insertBefore(document.createTextNode(text[i++]), cur);
        setTimeout(type, 70 + Math.random() * 40);
      } else {
        setTimeout(function() {
          var sub = document.getElementById('hero-sub');
          var bio = document.getElementById('hero-bio');
          var act = document.getElementById('hero-actions');
          if (sub) sub.classList.add('visible');
          if (bio) bio.classList.add('visible');
          if (act) act.classList.add('visible');
        }, 250);
      }
    }
    setTimeout(type, 400);
  }

  /* NAV SCROLL */
  function initNavScroll() {
    var nav = document.querySelector('.nav');
    if (!nav) return;
    var last = window.scrollY;
    window.addEventListener('scroll', function() {
      var cur = window.scrollY;
      if (cur > last && cur > 80) nav.classList.add('hidden');
      else nav.classList.remove('hidden');
      last = cur;
    }, { passive: true });
  }

  /* ACTIVE NAV */
  function initActiveNav() {
    var sections = document.querySelectorAll('section[id]');
    var links = document.querySelectorAll('.nav-links a[href^="#"]');
    if (!sections.length || !links.length) return;
    var obs = new IntersectionObserver(function(entries) {
      entries.forEach(function(e) {
        if (e.isIntersecting) {
          links.forEach(function(a) {
            a.classList.toggle('active', a.getAttribute('href').slice(1) === e.target.id);
          });
        }
      });
    }, { rootMargin: '-40% 0px -55% 0px' });
    sections.forEach(function(s) { obs.observe(s); });
  }

  /* HAMBURGER */
  function initHamburger() {
    var btn = document.getElementById('nav-hamburger');
    var overlay = document.getElementById('nav-overlay');
    if (!btn || !overlay) return;
    btn.addEventListener('click', function() {
      var open = overlay.classList.toggle('open');
      btn.classList.toggle('open', open);
      btn.setAttribute('aria-expanded', open);
      document.body.style.overflow = open ? 'hidden' : '';
    });
    overlay.querySelectorAll('a').forEach(function(a) {
      a.addEventListener('click', function() {
        overlay.classList.remove('open');
        btn.classList.remove('open');
        btn.setAttribute('aria-expanded', 'false');
        document.body.style.overflow = '';
      });
    });
  }

  /* REVEAL */
  function initReveal() {
    var els = document.querySelectorAll('.reveal, .reveal-stagger');
    if (!els.length) return;
    var obs = new IntersectionObserver(function(entries) {
      entries.forEach(function(e) {
        if (e.isIntersecting) { e.target.classList.add('revealed'); obs.unobserve(e.target); }
      });
    }, { threshold: 0.08, rootMargin: '0px 0px -40px 0px' });
    els.forEach(function(el) { obs.observe(el); });
  }

  /* FILTER */
  function initFilter() {
    var btns = document.querySelectorAll('.filter-btn');
    var cards = document.querySelectorAll('.writeup-card');
    if (!btns.length || !cards.length) return;
    btns.forEach(function(btn) {
      btn.addEventListener('click', function() {
        btns.forEach(function(b) { b.classList.remove('active'); });
        btn.classList.add('active');
        var cat = btn.dataset.cat || 'all';
        cards.forEach(function(c) {
          c.style.display = (cat === 'all' || c.dataset.category === cat) ? '' : 'none';
        });
      });
    });
  }

  /* SMOOTH SCROLL */
  function initScroll() {
    document.querySelectorAll('a[href^="#"]').forEach(function(a) {
      a.addEventListener('click', function(e) {
        var target = document.querySelector(a.getAttribute('href'));
        if (!target) return;
        e.preventDefault();
        window.scrollTo({ top: target.getBoundingClientRect().top + window.scrollY - 60, behavior: 'smooth' });
      });
    });
  }

  function init() {
    initCursor(); initTypewriter(); initNavScroll();
    initActiveNav(); initHamburger(); initReveal(); initFilter(); initScroll();
  }

  document.readyState === 'loading'
    ? document.addEventListener('DOMContentLoaded', init)
    : init();
})();
