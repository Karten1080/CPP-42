/* V3 — main.js · Finance */
(function () {
  'use strict';

  /* CURSOR */
  function initCursor() {
    var dot = document.getElementById('cursor');
    var ring = document.getElementById('cursor-ring');
    if (!dot) return;
    var rx = 0, ry = 0, dx = 0, dy = 0;
    document.addEventListener('mousemove', function(e) {
      dx = e.clientX; dy = e.clientY;
      dot.style.left = dx + 'px'; dot.style.top = dy + 'px';
    }, { passive: true });
    if (ring) {
      (function loop() {
        rx += (dx - rx) * 0.14; ry += (dy - ry) * 0.14;
        ring.style.left = rx + 'px'; ring.style.top = ry + 'px';
        requestAnimationFrame(loop);
      })();
    }
    document.addEventListener('mouseleave', function() { dot.style.opacity='0'; if(ring)ring.style.opacity='0'; });
    document.addEventListener('mouseenter', function() { dot.style.opacity='1'; if(ring)ring.style.opacity='1'; });
    document.querySelectorAll('a,button,.card,.badge,.filter-btn,.stat-card').forEach(function(el) {
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
    cur.className = 'cursor-type'; cur.setAttribute('aria-hidden','true');
    el.appendChild(cur);
    var i = 0;
    function type() {
      if (i < text.length) {
        el.insertBefore(document.createTextNode(text[i++]), cur);
        setTimeout(type, 70 + Math.random() * 35);
      } else {
        setTimeout(function() {
          ['hero-sub','hero-bio','hero-actions'].forEach(function(id) {
            var e = document.getElementById(id);
            if (e) e.classList.add('visible');
          });
        }, 200);
      }
    }
    setTimeout(type, 350);
  }

  /* COUNTER ANIMATION sur les stats */
  function initCounters() {
    var stats = document.querySelectorAll('.stat-value[data-target]');
    if (!stats.length) return;
    var obs = new IntersectionObserver(function(entries) {
      entries.forEach(function(entry) {
        if (!entry.isIntersecting) return;
        var el = entry.target;
        var target = parseInt(el.dataset.target);
        var suffix = el.dataset.suffix || '';
        var unit = el.querySelector('.unit');
        var unitHTML = unit ? unit.outerHTML : '';
        var duration = 1200;
        var start = performance.now();
        function tick(now) {
          var p = Math.min((now - start) / duration, 1);
          var val = Math.floor(p * target);
          el.textContent = val + suffix;
          if (unitHTML) el.insertAdjacentHTML('beforeend', unitHTML);
          if (p < 1) requestAnimationFrame(tick);
        }
        requestAnimationFrame(tick);
        obs.unobserve(el);
      });
    }, { threshold: 0.5 });
    stats.forEach(function(s) { obs.observe(s); });
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
        if (e.isIntersecting)
          links.forEach(function(a) {
            a.classList.toggle('active', a.getAttribute('href').slice(1) === e.target.id);
          });
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
        overlay.classList.remove('open'); btn.classList.remove('open');
        btn.setAttribute('aria-expanded','false'); document.body.style.overflow='';
      });
    });
  }

  /* REVEAL */
  function initReveal() {
    var els = document.querySelectorAll('.reveal,.reveal-stagger');
    if (!els.length) return;
    var obs = new IntersectionObserver(function(entries) {
      entries.forEach(function(e) {
        if (e.isIntersecting) { e.target.classList.add('revealed'); obs.unobserve(e.target); }
      });
    }, { threshold: 0.08, rootMargin: '0px 0px -32px 0px' });
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
          c.style.display = (cat==='all' || c.dataset.category===cat) ? '' : 'none';
        });
      });
    });
  }

  /* SMOOTH SCROLL */
  function initScroll() {
    document.querySelectorAll('a[href^="#"]').forEach(function(a) {
      a.addEventListener('click', function(e) {
        var t = document.querySelector(a.getAttribute('href'));
        if (!t) return; e.preventDefault();
        window.scrollTo({ top: t.getBoundingClientRect().top + window.scrollY - 60, behavior: 'smooth' });
      });
    });
  }

  function init() {
    initCursor(); initTypewriter(); initCounters();
    initNavScroll(); initActiveNav(); initHamburger();
    initReveal(); initFilter(); initScroll();
  }

  document.readyState === 'loading'
    ? document.addEventListener('DOMContentLoaded', init)
    : init();
})();
