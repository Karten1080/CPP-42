/* ============================================================
   main.js — Init, scroll, typewriter, nav, reveal
   ============================================================ */

(function () {
  'use strict';

  /* ===== CUSTOM CURSOR ===== */
  function initCursor() {
    const dot  = document.getElementById('cursor');
    const ring = document.getElementById('cursor-ring');
    if (!dot) return;

    let ringX = 0, ringY = 0;
    let dotX  = 0, dotY  = 0;
    let raf;

    function lerp(a, b, t) { return a + (b - a) * t; }

    document.addEventListener('mousemove', function (e) {
      dotX = e.clientX;
      dotY = e.clientY;
      dot.style.left = dotX + 'px';
      dot.style.top  = dotY + 'px';
    }, { passive: true });

    // Anneau avec léger lag
    if (ring) {
      function animateRing() {
        ringX = lerp(ringX, dotX, 0.12);
        ringY = lerp(ringY, dotY, 0.12);
        ring.style.left = ringX + 'px';
        ring.style.top  = ringY + 'px';
        raf = requestAnimationFrame(animateRing);
      }
      animateRing();
    }

    document.addEventListener('mouseleave', function () {
      dot.style.opacity = '0';
      if (ring) ring.style.opacity = '0';
    });
    document.addEventListener('mouseenter', function () {
      dot.style.opacity = '1';
      if (ring) ring.style.opacity = '1';
    });

    // Hover sur éléments interactifs
    document.querySelectorAll('a, button, .card, .badge, .filter-btn').forEach(function (el) {
      el.addEventListener('mouseenter', function () { document.body.classList.add('cursor-hover'); });
      el.addEventListener('mouseleave', function () { document.body.classList.remove('cursor-hover'); });
    });
  }

  /* ===== TYPEWRITER EFFECT ===== */
  function initTypewriter() {
    const el = document.getElementById('hero-name');
    if (!el) return;

    const text = el.dataset.text || el.textContent.trim();
    el.textContent = '';

    // Curseur clignotant
    const cursorSpan = document.createElement('span');
    cursorSpan.className = 'cursor-type';
    cursorSpan.setAttribute('aria-hidden', 'true');
    el.appendChild(cursorSpan);

    let i = 0;

    function type() {
      if (i < text.length) {
        el.insertBefore(document.createTextNode(text[i]), cursorSpan);
        i++;
        setTimeout(type, 75 + Math.random() * 40);
      } else {
        // Fin typewriter — révéler les éléments suivants
        setTimeout(function () {
          var h2  = document.getElementById('hero-h2');
          var bio = document.getElementById('hero-bio');
          var act = document.getElementById('hero-actions');
          if (h2)  h2.classList.add('visible');
          if (bio) bio.classList.add('visible');
          if (act) act.classList.add('visible');
        }, 300);
      }
    }

    // Démarrage décalé pour laisser la page charger
    setTimeout(type, 500);
  }

  /* ===== NAV HIDE / SHOW AU SCROLL ===== */
  function initNavScroll() {
    const nav = document.querySelector('.nav');
    if (!nav) return;

    let lastY = window.scrollY;

    window.addEventListener('scroll', function () {
      const currentY = window.scrollY;

      if (currentY > lastY && currentY > 100) {
        nav.classList.add('hidden');
      } else {
        nav.classList.remove('hidden');
      }

      lastY = currentY;
    }, { passive: true });
  }

  /* ===== LIENS NAV ACTIFS ===== */
  function initActiveNav() {
    const sections = document.querySelectorAll('section[id]');
    const navLinks  = document.querySelectorAll('.nav-links a[href^="#"]');

    if (!sections.length || !navLinks.length) return;

    const observer = new IntersectionObserver(function (entries) {
      entries.forEach(function (entry) {
        if (entry.isIntersecting) {
          navLinks.forEach(function (a) {
            const href = a.getAttribute('href').replace('#', '');
            if (href === entry.target.id) {
              a.classList.add('active');
            } else {
              a.classList.remove('active');
            }
          });
        }
      });
    }, { rootMargin: '-40% 0px -55% 0px', threshold: 0 });

    sections.forEach(function (s) { observer.observe(s); });
  }

  /* ===== HAMBURGER MOBILE ===== */
  function initHamburger() {
    const btn     = document.getElementById('nav-hamburger');
    const overlay = document.getElementById('nav-overlay');
    if (!btn || !overlay) return;

    btn.addEventListener('click', function () {
      const isOpen = overlay.classList.toggle('open');
      btn.classList.toggle('open', isOpen);
      btn.setAttribute('aria-expanded', isOpen);
      document.body.style.overflow = isOpen ? 'hidden' : '';
    });

    // Fermer au clic sur un lien
    overlay.querySelectorAll('a').forEach(function (a) {
      a.addEventListener('click', function () {
        overlay.classList.remove('open');
        btn.classList.remove('open');
        btn.setAttribute('aria-expanded', 'false');
        document.body.style.overflow = '';
      });
    });
  }

  /* ===== SCROLL REVEAL ===== */
  function initReveal() {
    const revealEls = document.querySelectorAll('.reveal, .reveal-stagger');
    if (!revealEls.length) return;

    const observer = new IntersectionObserver(function (entries) {
      entries.forEach(function (entry) {
        if (entry.isIntersecting) {
          entry.target.classList.add('revealed');
          observer.unobserve(entry.target);
        }
      });
    }, { threshold: 0.1, rootMargin: '0px 0px -48px 0px' });

    revealEls.forEach(function (el) { observer.observe(el); });
  }

  /* ===== FILTRE WRITE-UPS (page writeups) ===== */
  function initWriteupFilter() {
    const filterBtns = document.querySelectorAll('.filter-btn');
    const cards      = document.querySelectorAll('.writeup-card');
    if (!filterBtns.length || !cards.length) return;

    filterBtns.forEach(function (btn) {
      btn.addEventListener('click', function () {
        filterBtns.forEach(function (b) { b.classList.remove('active'); });
        btn.classList.add('active');

        const cat = btn.dataset.cat || 'all';

        cards.forEach(function (card) {
          if (cat === 'all' || card.dataset.category === cat) {
            card.style.display = '';
          } else {
            card.style.display = 'none';
          }
        });
      });
    });
  }

  /* ===== SMOOTH SCROLL (ancres) ===== */
  function initSmoothScroll() {
    document.querySelectorAll('a[href^="#"]').forEach(function (a) {
      a.addEventListener('click', function (e) {
        const target = document.querySelector(a.getAttribute('href'));
        if (!target) return;
        e.preventDefault();
        const navH = document.querySelector('.nav') ? 64 : 0;
        const top  = target.getBoundingClientRect().top + window.scrollY - navH;
        window.scrollTo({ top: top, behavior: 'smooth' });
      });
    });
  }

  /* ===== INIT ===== */
  function init() {
    initCursor();
    initTypewriter();
    initNavScroll();
    initActiveNav();
    initHamburger();
    initReveal();
    initWriteupFilter();
    initSmoothScroll();
  }

  if (document.readyState === 'loading') {
    document.addEventListener('DOMContentLoaded', init);
  } else {
    init();
  }
})();
