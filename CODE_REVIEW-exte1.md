# Code Review — exte1 (vectori, stil LeetCode) — reanaliză completă

**Stadiu:** 1 ✅⚠️ · 2 ✅ · 3 ✅ · 4 ✅ · 5 ✅⚠️ · 6 ✅ · 7 ✅ · 8 ✅ · 9 ✅ · 10 ✅ — **toate 10 rezolvate.**

**Vestea mare:** de la review-ul trecut (erai la 1–5) ai rezolvat **6, 7, 8, 9 și 10**, iar toate cinci sunt **corecte pe exemplele din fișă** — verificate prin rulare, nu doar citite. Trei merită subliniate:

- **Problema 7 (rotire)** — tripla inversare, exact metoda elegantă. `O(n)`, fără vector auxiliar. Curat.
- **Problema 8 (sume prefix)** — decalajul `p[dr+1] - p[st]` e corect, `long long` pus unde trebuie. Ai prins că `p` are `n+1` poziții.
- **Problema 9 (produs fără sine)** — corectă, dar mai important: **ți-ai scris trace-ul de mână în comentarii** (liniile 176–193), cu prefix și sufix pas cu pas. Aia nu e cod copiat — e cod **înțeles**. Exact așa se învață. (Le poți șterge după ce merge, dar ca dovadă de înțelegere sunt aur.)

**Vestea repetată:** cele **două bug-uri 🔴 din review-ul trecut sunt tot acolo**, neatinse — B1 la problema 1 și B2 la afișarea problemei 5. Ai construit cinci probleme corecte peste ele, dar n-ai reparat fundația. E fix pattern-ul de la culegere: algoritmica ta aleargă înaintea igienei de proiect.

## 🔴 Bug-uri critice (deschise din review-ul trecut)

**B1 — `perecheSuma` întoarce ULTIMA pereche, nu PRIMA** (`functii-exte1.h:27-29`). Enunțul cere „prima pereche". Lipsește `return` după potrivire, deci bucla continuă și suprascrie cu următoarea. Confirmat prin rulare:

| Input | Corect (prima) | Ce afișează codul tău |
|---|---|---|
| `1 2 3 4`, S=5 | `0 3` (1+4) | `1 2` (2+3) — ultima |

Pe exemplul din fișă (`2 7 11 15 3`, S=9) a mers doar fiindcă acolo e o singură pereche. „Primul care..." înseamnă **ieși imediat ce l-ai găsit**.

**Before** (`functii-exte1.h:25-29`):
```cpp
if(v[i]+v[j]==S)
{
    pi=i;
    pj=j;
}
```
**After:**
```cpp
if(v[i]+v[j]==S)
{
    pi=i;
    pj=j;
    return;
}
```

**B2 — `solutie5a` afișează gunoiul de după `k`** (`solutii-exte1.h:46`). `stergereDubluri` întoarce `k=5` corect, dar afișezi `afisareVector(v, n)` cu `n=10`. Pozițiile `k..n-1` conțin resturi de dinainte de compactare. Rulat acum:

| Ce cere enunțul | Ce afișează codul tău |
|---|---|
| `5` apoi `1 2 3 5 7` | `5` apoi `1 2 3 5 7 3 3 5 5 7` |

**Before** (`solutii-exte1.h:46`): `afisareVector(v,n);`
**After:** `afisareVector(v,k);`

## 🟡 Issue-uri importante

**M1 — nimic nu citește din `data.txt`** (toate `solutieN`). Ai chiar un `data.txt` în repo (`6` / `19 24 65 23 13 68`) pe care **nicio soluție nu-l folosește** — toți vectorii sunt hardcodați în cod. Prima regulă din fișă e „datele se citesc din `data.txt`". Fără asta nu poți rula un al doilea input fără să recompilezi — adică nu poți face fix „Verifică-te".

**M2 — semnătura de la 5 e schimbată** (`functii-exte1.h:91`). Fișa dă `int stergeDuplicate(...)`; tu ai scris `stergereDubluri`. Regula: „Nu modifica semnăturile."

**M3 — `main.cpp` rupe tiparul `solutieN`** (`main.cpp:1-9`). Pentru problema 10 apelezi `apaAdunata(v,12)` **direct în main**, nu printr-o `solutie10a()` ca la restul; în plus ai două tablouri `maxSt[100]`, `maxDr[100]` (liniile 6–7) care nu se folosesc nicăieri. Fă o `solutie10a()` în `solutii-exte1.h` (care construiește vectorul și cheamă `apaAdunata`) și lasă `main` doar cu un apel, ca la celelalte.

**M4 — header guard-uri invalide** (`functii-exte1.h:1-2`, `solutii-exte1.h:1-2`). `#ifndef FUNCTII-EXTE1_H_INCLUDED` — cratima nu e permisă într-un macro; compilatorul dă `warning: extra tokens at end of #ifndef directive` (5 warning-uri la build) și folosește de fapt doar `FUNCTII`. Merge acum, dar e fragil. Fix: `FUNCTII_EXTE1_H_INCLUDED` (underscore).

## 🟢 Cleanups

1. **Cod mort: `maximStanga` și `maximDreapta`** (`functii-exte1.h:210-241`). Le-ai scris ca funcții separate, dar `apaAdunata` **nu le apelează** — a doua oară calculezi aceiași maximi inline (liniile 247–265). Ori chemi helper-ele din `apaAdunata` (mai curat), ori ștergi funcțiile nefolosite. Acum ai algoritmul scris de două ori.
2. **`solutie1a` apelează `perecheSuma` de 5 ori degeaba** (`solutii-exte1.h:11-14`). Bucla `for(i<n)` cheamă aceeași funcție pe același vector — un singur apel ajunge.
3. **`rotesteDreapta` fără gardă `n==0`** (`functii-exte1.h:152`). `k=k%n` împarte la zero dacă `n==0`. Pe inputurile din fișă nu apare, dar `if(n==0) return;` la început e reflexul corect. Idem `stergereDubluri` (fără `if(n==0) return 0;`).
4. **`solutie5a`: 11 valori dar `n=10`** (`solutii-exte1.h:42`). `{1,1,2,2,3,3,3,5,5,7,7}` are 11 elemente; ultimul `7` e ignorat în tăcere. Fă `n` să corespundă exact.
5. **`solutie8a` hardcodează query-urile** (`solutii-exte1.h:70-71`). `st[]` și `dr[]` sunt scrise manual în loc să fie citite. Merge, dar leagă-le de M1: query-urile vin din `data.txt`.

## Pașii următori

| Prioritate | Ce | Notă |
|---|---|---|
| **1** | `fix: exercitiul 1 - return la prima pereche` | B1 — o linie |
| **2** | `fix: exercitiul 5 - afisez k, nu n` | B2 — o linie |
| 3 | Șterge codul mort de la 10 (sau cheamă helper-ele) | C1 |
| 4 | `solutie10a()` + citire din `data.txt` peste tot | M3 + M1 |
| 5 | Repară guard-urile (underscore) | M4 |

## Sinteză

| Criteriu | Review trecut | Acum |
|---|---|---|
| Progres | 1–5 | **1–10 (complet)** |
| Bug-uri critice noi în 6–10 | — | **0** ✅ |
| Bug-uri critice deschise total | 2 | 2 ⚠️ (aceleași) |
| Cod mort / hygiene | — | apărut la 10 (C1) |

Cinci probleme noi, zero bug-uri de logică nouă — asta e algoritmică bună. Diferența până la „programator", nu doar „rezolvitor de probleme", sunt cele două linii de la B1 și B2 pe care le tot amâni. Review-ul următor începe cu ele.

## Q&A — verifică-te

1. La 1, cu ce input **din repo** (nu inventat) ai putea demonstra singur bug-ul B1? (Indiciu: îți trebuie un vector cu **două** perechi care dau `S` — `data.txt`-ul actual are așa ceva pentru un `S` potrivit?)
2. `stergereDubluri` întoarce `k=5` corect, dar afișarea e greșită. De ce sunt funcția și apelul de afișare **două responsabilități separate**, și care avea bug-ul?
3. La problema 10 ai scris `maximStanga`/`maximDreapta` ca funcții, dar `apaAdunata` le recalculează inline. Care variantă o ștergi și de ce e mai rău să ai algoritmul scris în două locuri?

---

*Stop aici. Repară B1 + B2 (două linii), apoi scrie „next".*
