/* ============================================================
   V4 — main.js · Nav, Scroll, Typewriter, Reveal, Clock, Filter
   ============================================================ */
(function () {
  'use strict';

  /* ===== SCROLL PROGRESS BAR ===== */
  function initScrollBar() {
    var bar = document.getElementById('scroll-progress');
    if (!bar) return;
    window.addEventListener('scroll', function () {
      var pct = window.scrollY / (document.body.scrollHeight - window.innerHeight) * 100;
      bar.style.width = Math.min(pct, 100) + '%';
    }, { passive: true });
  }

  /* ===== NAV HIDE/SHOW ===== */
  function initNavScroll() {
    var nav  = document.querySelector('.nav');
    if (!nav) return;
    var last = window.scrollY;
    window.addEventListener('scroll', function () {
      var cur = window.scrollY;
      if (cur > last && cur > 100) nav.classList.add('hidden');
      else nav.classList.remove('hidden');
      last = cur;
    }, { passive: true });
  }

  /* ===== ACTIVE NAV LINKS ===== */
  function initActiveNav() {
    var sections = document.querySelectorAll('section[id]');
    var links    = document.querySelectorAll('.nav-links a[href^="#"]');
    if (!sections.length || !links.length) return;
    var obs = new IntersectionObserver(function (entries) {
      entries.forEach(function (e) {
        if (e.isIntersecting) {
          links.forEach(function (a) {
            a.classList.toggle('active', a.getAttribute('href').slice(1) === e.target.id);
          });
        }
      });
    }, { rootMargin: '-40% 0px -55% 0px' });
    sections.forEach(function (s) { obs.observe(s); });
  }

  /* ===== HAMBURGER ===== */
  function initHamburger() {
    var btn     = document.getElementById('nav-hamburger');
    var overlay = document.getElementById('nav-overlay');
    if (!btn || !overlay) return;
    btn.addEventListener('click', function () {
      var open = overlay.classList.toggle('open');
      btn.classList.toggle('open', open);
      btn.setAttribute('aria-expanded', open);
      document.body.style.overflow = open ? 'hidden' : '';
    });
    overlay.querySelectorAll('a').forEach(function (a) {
      a.addEventListener('click', function () {
        overlay.classList.remove('open');
        btn.classList.remove('open');
        btn.setAttribute('aria-expanded', 'false');
        document.body.style.overflow = '';
      });
    });
  }

  /* ===== TYPEWRITER (hero name) ===== */
  function initTypewriter() {
    var el = document.getElementById('hero-name');
    if (!el) return;
    var text = el.dataset.text || el.textContent.trim();

    // Clear and add cursor
    el.textContent = '';
    var cur = document.createElement('span');
    cur.className = 'cur'; cur.setAttribute('aria-hidden', 'true');
    el.appendChild(cur);

    var i = 0;
    var startDelay = 1900; // after loader

    function type() {
      if (i < text.length) {
        el.insertBefore(document.createTextNode(text[i++]), cur);
        setTimeout(type, 65 + Math.random() * 35);
      } else {
        cur.remove();
        // Reveal subsequent elements
        setTimeout(function () {
          ['hero-sub','hero-bio','hero-actions'].forEach(function (id) {
            var e = document.getElementById(id);
            if (e) e.classList.add('visible');
          });
        }, 200);
      }
    }

    setTimeout(type, startDelay);
  }

  /* ===== SCROLL REVEAL ===== */
  function initReveal() {
    var els = document.querySelectorAll('.reveal, .reveal-stagger');
    if (!els.length) return;
    var obs = new IntersectionObserver(function (entries) {
      entries.forEach(function (e) {
        if (e.isIntersecting) { e.target.classList.add('revealed'); obs.unobserve(e.target); }
      });
    }, { threshold: 0.08, rootMargin: '0px 0px -32px 0px' });
    els.forEach(function (el) { obs.observe(el); });
  }

  /* ===== LIVE CLOCK (Paris) ===== */
  function initClock() {
    var el = document.getElementById('nav-clock');
    if (!el) return;
    function tick() {
      var now = new Date();
      var str = now.toLocaleTimeString('fr-FR', { timeZone: 'Europe/Paris', hour: '2-digit', minute: '2-digit', second: '2-digit' });
      el.textContent = 'PARIS ' + str;
    }
    tick();
    setInterval(tick, 1000);
  }

  /* ===== WRITEUP FILTER ===== */
  function initFilter() {
    var btns  = document.querySelectorAll('.filter-btn');
    var cards = document.querySelectorAll('.writeup-card');
    if (!btns.length || !cards.length) return;
    btns.forEach(function (btn) {
      btn.addEventListener('click', function () {
        btns.forEach(function (b) { b.classList.remove('active'); });
        btn.classList.add('active');
        var cat = btn.dataset.cat || 'all';
        cards.forEach(function (c) {
          c.style.display = (cat === 'all' || c.dataset.category === cat) ? '' : 'none';
        });
      });
    });
  }

  /* ===== SMOOTH SCROLL ===== */
  function initSmoothScroll() {
    document.querySelectorAll('a[href^="#"]').forEach(function (a) {
      a.addEventListener('click', function (e) {
        var target = document.querySelector(a.getAttribute('href'));
        if (!target) return;
        e.preventDefault();
        window.scrollTo({ top: target.getBoundingClientRect().top + window.scrollY - 60, behavior: 'smooth' });
      });
    });
  }

  /* ===== INIT ===== */
  function init() {
    initScrollBar();
    initNavScroll();
    initActiveNav();
    initHamburger();
    initTypewriter();
    initReveal();
    initClock();
    initFilter();
    initSmoothScroll();
  }

  document.readyState === 'loading'
    ? document.addEventListener('DOMContentLoaded', init)
    : init();
})();
