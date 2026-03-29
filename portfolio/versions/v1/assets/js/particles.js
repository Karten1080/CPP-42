/* ============================================================
   particles.js — Effet particules canvas sur le hero
   Vanilla JS pur, aucune lib externe
   ============================================================ */

(function () {
  'use strict';

  const PARTICLE_COUNT = 80;
  const MAX_DIST = 120;
  const COLORS = [
    'rgba(0, 255, 136, 0.6)',
    'rgba(0, 255, 136, 0.4)',
    'rgba(0, 212, 255, 0.4)',
    'rgba(0, 212, 255, 0.25)',
  ];

  let canvas, ctx, particles, animId, W, H;

  function init() {
    canvas = document.getElementById('particles-canvas');
    if (!canvas) return;

    ctx = canvas.getContext('2d');
    resize();
    particles = Array.from({ length: PARTICLE_COUNT }, createParticle);
    cancelAnimationFrame(animId);
    loop();
  }

  function resize() {
    if (!canvas) return;
    const hero = canvas.parentElement;
    W = canvas.width  = hero ? hero.offsetWidth  : window.innerWidth;
    H = canvas.height = hero ? hero.offsetHeight : window.innerHeight;
  }

  function createParticle() {
    return {
      x:    Math.random() * W,
      y:    Math.random() * H,
      vx:   (Math.random() - 0.5) * 0.6,
      vy:   (Math.random() - 0.5) * 0.6,
      r:    Math.random() * 1 + 1,
      color: COLORS[Math.floor(Math.random() * COLORS.length)],
    };
  }

  function update(p) {
    p.x += p.vx;
    p.y += p.vy;
    if (p.x < 0 || p.x > W) p.vx *= -1;
    if (p.y < 0 || p.y > H) p.vy *= -1;
  }

  function draw() {
    ctx.clearRect(0, 0, W, H);

    for (let i = 0; i < particles.length; i++) {
      const a = particles[i];

      // Draw dot
      ctx.beginPath();
      ctx.arc(a.x, a.y, a.r, 0, Math.PI * 2);
      ctx.fillStyle = a.color;
      ctx.fill();

      // Draw connecting lines
      for (let j = i + 1; j < particles.length; j++) {
        const b = particles[j];
        const dx = a.x - b.x;
        const dy = a.y - b.y;
        const dist = Math.sqrt(dx * dx + dy * dy);

        if (dist < MAX_DIST) {
          const alpha = (1 - dist / MAX_DIST) * 0.18;
          ctx.beginPath();
          ctx.moveTo(a.x, a.y);
          ctx.lineTo(b.x, b.y);
          ctx.strokeStyle = `rgba(0, 255, 136, ${alpha})`;
          ctx.lineWidth = 0.5;
          ctx.stroke();
        }
      }
    }
  }

  function loop() {
    particles.forEach(update);
    draw();
    animId = requestAnimationFrame(loop);
  }

  // Init on DOM ready
  if (document.readyState === 'loading') {
    document.addEventListener('DOMContentLoaded', init);
  } else {
    init();
  }

  // Handle resize with debounce
  let resizeTimer;
  window.addEventListener('resize', function () {
    clearTimeout(resizeTimer);
    resizeTimer = setTimeout(function () {
      resize();
      if (particles) {
        particles.forEach(function (p) {
          p.x = Math.min(p.x, W);
          p.y = Math.min(p.y, H);
        });
      }
    }, 150);
  });
})();
