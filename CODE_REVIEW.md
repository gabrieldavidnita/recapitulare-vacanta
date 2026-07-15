# Code Review #3 — recapitulare-vacanta

**Stadiu:** 1a ✅ · 1b ✅ · 1c ✅ (`solutie3` + `frecventaMinimului`).

**Vestea bună întâi:** e prima ta rezolvare **fără niciun bug critic nou**. Și ai văzut singur capcana problemei — că minimul poate fi *după* maxim — și ai tratat-o cu swap-ul de la începutul lui `frecventaMinimului`. Exact asta e diferența dintre a traduce enunțul în cod și a gândi problema.

**Vestea mai puțin bună:** cele **5 bug-uri 🔴 din review-urile #1 și #2 sunt toate neatinse**. Două review-uri la rând ai mers înainte pe exerciții noi peste bug-uri cunoscute. În proiecte reale asta se numește datorie tehnică și se plătește cu dobândă: 1c folosește `functii.h`, unde stau 3 din ele.

## Regula pentru pasul următor

**Nu începe 1d.** Următorul commit trebuie să fie `fix: bug-urile din code review 1 si 2`. Lista completă, cu fix-urile deja scrise în review-urile anterioare:

| # | Bug | Unde | Din review |
|---|---|---|---|
| 1 | Zerorizare `i<9999` vs scanare `i<=9999` | `functii.h:67` / `functii.h:79` | #1 |
| 2 | `valMinima` fără `return` pe toate căile | `functii.h:77-86` | #1 |
| 3 | Numere negative sparg vectorul de frecvență | `functii.h:73` | #1 |
| 4 | `if(n>13)` respinge exact cazul n=13 | `solutii.h:34` | #2 |
| 5 | `frecventaCifraVector` nu-și zerorizează `f` | `functii.h:88` | #2 |

**Verifică-te după fix:** compilezi cu `g++ -Wall main.cpp` fără niciun warning; rulezi `solutie1`, `solutie12`, `solutie2`, `solutie3` pe rând (schimbi apelul în `main`) și toate dau rezultate corecte pe `data.txt` cu `n=13` și pe un `data.txt` cu un număr negativ.

---

## 🔴 Bug-uri critice noi

**Niciunul.** Așa arată un commit bun.

---

## 🟡 Issue-uri minore în codul nou

1. **`valMin` + `pozMin` = două parcurgeri pentru aceeași informație** (`solutii.h:31-33`). Minimul *este* elementul de la poziția minimului: `int mn = v[pmin];`. O funcție în minus de apelat, o parcurgere în minus, zero cod nou. Aceeași observație rămâne valabilă pentru `valMax` vs `pozMax` din review #2 — vezi tiparul?
2. **Ramura de swap nu e testată** — în `data.txt` curent minimul (poziția 0) e înaintea maximului (poziția 9), deci swap-ul tău nu rulează niciodată. Un cod netestat e un cod despre care doar *speri* că merge. Mută 4364 la începutul vectorului și verifică că rezultatul rămâne corect.
3. **Lipsește `endl` la ultima afișare** (`solutii.h:55`) — prompt-ul terminalului se lipește de rezultat.
4. **Spațiile din mesaje, a treia oară** — `" Minimul este "` cu spațiu în față, `"Pozitia minimului..."` fără; în review #1 și #2 același lucru. Alege o formă și ține-o peste tot.
5. **Afișezi pozițiile 1-indexat (`pmin+1`)** — alegere bună pentru om, dar atunci fă-o consecvent: în `solutie1` afișezi valori, aici poziții — un cititor nu are cum să știe convenția. Un comentariu scurt sau un mesaj explicit („poziția, numărând de la 1") rezolvă.

---

## 🟢 Pattern-uri corecte (continuă așa)

- **Swap-ul `pmin > pmax`** — ai anticipat singur cazul care pică 80% din rezolvările acestei probleme. De departe cel mai valoros lucru din commit.
- **Interval închis `[pmin, pmax]`** cu `<=` — exact ce cere enunțul.
- **Zero bug-uri critice noi** — prima dată.
- **Formatul de commit `feat: ...`** — aplicat din prima, fără să ți se mai spună.
- **Ai variat `data.txt`** (ai mutat maximul pe altă poziție) — instinct bun de testare; acum du-l până la capăt (vezi 🟡2).
- `frecventaMinimului` primește `mn` ca parametru în loc să-l recalculeze — separarea responsabilităților e corectă.

---

## Pașii următori

| Prioritate | Ce | Notă |
|---|---|---|
| **1** | `fix: bug-urile din code review 1 si 2` | tabelul de mai sus, toate 5 |
| 2 | 1d — toate elementele conțin cifra min sau max? | ai `contorCif`; îți lipsește doar `cifMinNumar` (oglinda lui `cifMaxNumar`) |
| 3 | 1e — primul minim absolut | citește exemplul din culegere de două ori înainte de cod |
| 4 | 1f, 1g — interschimbări | vei avea nevoie de vectorul **nemodificat** — amintește-ți 🟡1 din review #2 |

## Sinteză

| Criteriu | #1 | #2 | Acum |
|---|---|---|---|
| Progres culegere | 1a | 1a–1b | 1a–1c |
| Bug-uri critice noi în commit | 3 | 2 | **0** ✅ |
| Bug-uri critice deschise total | 3 | 5 | 5 ⚠️ |
| Format commit | ❌ | ⚠️ | ✅ |
| Testare proprie a edge case-urilor | ❌ | ❌ | ⚠️ început |

Curba e exact cea corectă: fiecare commit mai curat decât precedentul. Singurul lucru care strică tabloul e coada de bug-uri care crește în spate. Închide-o acum, cât e mică — după 1g ar fi de trei ori mai lungă și de trei ori mai greu de debugat.
