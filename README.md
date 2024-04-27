# IZLO projekt 1 a 2 2023/2024
Projekty na SAT a SMT solvery
# Hodnocení projektu 1
```
* Základní testy (max 4 body): Testy, které jste měli k dispozici. Tyto testy spustí váš generátor a SAT solver nad vygenerovanou formulí a ověří status (SAT/UNSAT) a korektnost modelu nalezeného solverem. Nicméně SAT solver může teoreticky najít korektní model i pro nekorektní formuli (např. pro formuli true může solver najít jak korektní, tak nekorektní model).

Zakladní testy:
  tests/sat/complex.in: OK
  tests/sat/loop.in: OK
  tests/sat/multiple_paths.in: OK
  tests/sat/one_edge.in: OK
  tests/sat/path_with_self_loops.in: OK
  tests/sat/self_loop.in: OK
  tests/sat/simple_path.in: OK
  tests/unsat/diamond.in: OK
  tests/unsat/loop_in_middle.in: OK
  tests/unsat/many_random.in: OK
  tests/unsat/same_dir.in: OK
  tests/unsat/simple_path_disconnected.in: OK
  tests/unsat/two_disconnected.in: OK

Body: 4.0 (max 4)
====================================================================
* Pokročilé testy (max 4 bodů) testují logickou ekvivalenci vámi vygenerované formule s referenčním řešením. Jelikož je množina proměnných pevně daná, musí logická ekvivalence pro korektní řešení vždy platit. Častým problémem, který se neprojevil v základní sadě testů, je nějaká forma off-by-one chyby - např. ve funkci streets_connected, kde pro poslední ulici již nemá existovat navazující ulice.

Testy ekvivalence:
  tests/sat/complex.in: OK
  tests/sat/loop.in: OK
  tests/sat/multiple_paths.in: OK
  tests/sat/one_edge.in: OK
  tests/sat/path_with_self_loops.in: OK
  tests/sat/self_loop.in: OK
  tests/sat/simple_path.in: OK
  tests/unsat/diamond.in: OK
  tests/unsat/loop_in_middle.in: OK
  tests/unsat/many_random.in: OK
  tests/unsat/same_dir.in: OK
  tests/unsat/simple_path_disconnected.in: OK
  tests/unsat/two_disconnected.in: OK

Body: 4.0 (max 4)
====================================================================

Součet bodů: 8.0
```
# Hodnocení projektu 2
```
10/10
```