# CLAUDE.md — Portfolio Adel Smati (V2)

> Ce fichier est le cerveau du projet pour toute IA qui reprend ce travail.
> Lis-le entièrement avant de modifier quoi que ce soit.
> Ne pose aucune question à l'utilisateur — tout est ici.

---

## QUI EST L'UTILISATEUR

**Adel Smati** — Étudiant École 42 Paris, cherche un stage Cybersécurité (Pentest / SOC) 6 mois dès **mai 2026**.

- Email : adel.smati@gmail.com
- LinkedIn : linkedin.com/in/adel-smati-23492337a
- GitHub : github.com/adel-smati
- Paris · Permis B

---

## STRUCTURE DU PROJET

```
adel-smati.github.io/
├── index.html                    ← page principale
├── assets/
│   ├── css/
│   │   ├── main.css              ← reset + variables + layout global
│   │   ├── components.css        ← nav, cards, badges, boutons, grids
│   │   └── animations.css        ← toutes les animations CSS + grain texture
│   ├── js/
│   │   ├── main.js               ← cursor, typewriter, nav, reveal, filtre
│   │   └── particles.js          ← effet particules canvas (hero)
│   └── data/
│       └── writeups.json         ← données write-ups CTF
├── writeups/
│   └── index.html                ← page liste write-ups avec filtre
├── .github/
│   └── workflows/
│       └── deploy.yml            ← GitHub Actions déploiement auto
├── CLAUDE.md                     ← ce fichier (ne pas supprimer)
└── PROMPT_PORTFOLIO_V2.md        ← spec de référence
```

---

## DESIGN SYSTEM — RÈGLES ABSOLUES

### Variables CSS (dans main.css)
```css
--bg-primary: #070b11
--bg-secondary: #0d1420
--bg-tertiary: #111827
--accent-green: #00ff88
--accent-cyan: #00d4ff
--accent-red: #ff4757
--text-primary: #e8eaf0
--text-secondary: #8892a4
--text-muted: #4a5568
--border: rgba(0,255,136,0.12)
--border-hover: rgba(0,255,136,0.4)
```

### Fonts
- Titres : **JetBrains Mono** (Google Fonts, weight 700)
- Corps : **Sora** (Google Fonts, weight 400/500)
- **Jamais** Arial, Inter, Roboto, system-ui

### Layout
- Max-width : **860px**
- Padding horizontal : 24px mobile → 48px desktop
- Sections : padding vertical **80px mobile → 120px desktop**
- Gap cards : **24px** — Border-radius : **12px**
- Système d'espacement 8px strict : 8, 16, 24, 32, 48, 64, 80, 120

---

## CE QUI A ÉTÉ FAIT (session 2026-03-28)

- [x] `assets/css/main.css` — variables, reset, layout, cursor, utilities
- [x] `assets/css/components.css` — nav, boutons, cards, badges, pills, grids, hero, contact, footer, certifications, CVE cards, filtre write-ups
- [x] `assets/css/animations.css` — toutes les animations + grain texture overlay
- [x] `assets/js/particles.js` — 80 particules canvas, lignes entre proches, rebond bords, resize handler
- [x] `assets/js/main.js` — cursor custom, typewriter H1, nav hide/show scroll, active links IntersectionObserver, hamburger mobile, scroll reveal, filtre writeups, smooth scroll
- [x] `assets/data/writeups.json` — 3 write-ups d'exemple au format JSON
- [x] `index.html` — toutes les sections (hero, stack, projets 42, CTF, certifications, veille CVE, contact)
- [x] `writeups/index.html` — page write-ups avec filtre par catégorie JS vanilla
- [x] `.github/workflows/deploy.yml` — GitHub Actions déploiement sur push main

---

## CE QUI RESTE À FAIRE

### Obligatoire avant déploiement

1. **CV PDF** — mettre `cv-adel-smati.pdf` à la racine du repo.
   Le bouton "CV PDF" dans le hero pointe déjà vers `./cv-adel-smati.pdf`.

2. **Déploiement GitHub Pages** :
   ```bash
   git init
   git add .
   git commit -m "feat: portfolio cybersécurité v2"
   git branch -M main
   git remote add origin https://github.com/adel-smati/adel-smati.github.io.git
   git push -u origin main
   ```
   Puis dans Settings du repo GitHub → Pages → Source : `gh-pages` branch (créée auto par le workflow).

### Contenu à personnaliser

3. **Write-ups CTF réels** — remplacer les 3 write-ups fictifs par les vrais.
   - Dans `index.html` et `writeups/index.html` : éditer les `<article class="card writeup-card">`
   - Ou insérer avant `<!-- WRITEUP_INSERT -->` en respectant ce format :
   ```html
   <article class="card writeup-card" data-category="Web|Pwn|Réseau|Reverse">
     <p class="platform-tag">PLATEFORME · CATÉGORIE</p>
     <div class="card-header">
       <h3 class="card-title">Nom du challenge</h3>
       <span class="diff diff-easy|diff-medium|diff-hard">EASY|MEDIUM|HARD</span>
     </div>
     <p class="card-body">Résumé 2-3 lignes...</p>
     <a href="LIEN" class="writeup-link">→ Lire le write-up complet</a>
   </article>
   ```
   - Mettre à jour `assets/data/writeups.json` en parallèle

4. **Veille CVE réelle** — ajouter avant `<!-- VEILLE_INSERT -->` :
   ```html
   <div class="cve-card">
     <div class="cve-meta">
       <span class="cve-id">CVE-XXXX-XXXXX</span>
       <span class="cvss cvss-critical|cvss-high|cvss-medium">CVSS X.X</span>
       <span class="cve-date">YYYY-MM-DD</span>
     </div>
     <p class="cve-title">Titre court</p>
     <p class="cve-body">Analyse 4-5 lignes...</p>
   </div>
   ```

5. **Liens write-ups** — remplacer les `href="#"` dans les `writeup-link` par les vrais liens.

6. **Certifications** — quand une cert est obtenue, changer `in-progress` → `active` sur le `.status-dot`.

---

## COMMENTAIRES D'INSERTION (critiques — ne jamais supprimer)

Ces deux commentaires HTML sont présents dans `index.html` ET `writeups/index.html` :

- `<!-- WRITEUP_INSERT -->` — après les cards write-ups, pour insertion automatique
- `<!-- VEILLE_INSERT -->` — après les cards CVE, pour insertion automatique

---

## FONCTIONNEMENT DES JS

### particles.js
- Canvas `#particles-canvas` en `position: absolute` dans la section `#hero`
- 80 particules, rayon 1.5px, couleur vert/cyan, vitesse ±0.3
- Lignes entre particules < 120px, opacité proportionnelle à la distance
- Resize handler debounced 150ms

### main.js
- **Cursor** : `#cursor` suit la souris en fixed, clignote
- **Typewriter** : lit `data-text` sur `#hero-name`, écrit lettre par lettre (75ms + random), puis révèle `#hero-h2`, `#hero-bio`, `#hero-actions` via classe `visible`
- **Nav scroll** : `translateY(-100%)` si scroll down > 100px, revient au scroll up
- **Active links** : IntersectionObserver, rootMargin `-40% 0px -55% 0px`
- **Hamburger** : toggle classe `open` sur `#nav-overlay` et bouton, `overflow: hidden` sur body
- **Reveal** : IntersectionObserver sur `.reveal` et `.reveal-stagger` → classe `revealed`
- **Filtre** : `.filter-btn[data-cat]` filtre `.writeup-card[data-category]` en show/hide
- **Smooth scroll** : override des liens `href="#..."` pour offset nav height

---

## DÉPLOIEMENT

```bash
# 1. Créer le repo sur GitHub : adel-smati/adel-smati.github.io
# 2. Pousser le code :
git init
git add .
git commit -m "feat: portfolio cybersécurité v2"
git branch -M main
git remote add origin https://github.com/adel-smati/adel-smati.github.io.git
git push -u origin main

# 3. Le workflow GitHub Actions se déclenche automatiquement
# 4. Dans Settings → Pages → Source : branche gh-pages
# 5. Site disponible sur : https://adel-smati.github.io
```

Le workflow `deploy.yml` vérifie la structure, puis pousse sur `gh-pages` via `peaceiris/actions-gh-pages@v3`.
Il exclut automatiquement `CLAUDE.md` et les fichiers `.md` de prompt du déploiement.

---

## CE QU'IL NE FAUT JAMAIS FAIRE

- Inliner du CSS ou JS dans le HTML (sauf Google Fonts `<link>`)
- Utiliser Bootstrap, Tailwind, jQuery ou toute autre lib
- Fond blanc ou clair, couleurs pastels, violet
- Barres de progression pour les compétences
- Photo ou avatar
- Valeurs CSS aléatoires (respecter le système 8px)
- Lorem ipsum
- Casser le responsive mobile 375px

---

*Dernière mise à jour : 2026-03-28 · Claude Sonnet 4.6 · V2 multi-fichiers*
