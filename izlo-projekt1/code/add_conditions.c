#include <stddef.h>
#include "cnf.h"

//
// LOGIN: xhodanj00
//

// Tato funkce by mela do formule pridat klauzule predstavujici podminku 1)
// Křižovatky jsou reprezentovany cisly 0, 1, ..., num_of_crossroads-1
// Cislo num_of_streets predstavuje pocet ulic a proto i pocet kroku cesty
// Pole streets ma velikost num_of_streets a obsahuje vsechny existujuci ulice
//    - pro 0 <= i < num_of_streets predstavuje streets[i] jednu existujici
//      ulici od krizovatky streets[i].crossroad_from ke krizovatce streets[i].crossroad_to
void at_least_one_valid_street_for_each_step(CNF *formula, unsigned num_of_crossroads, unsigned num_of_streets, const Street *streets)
{
    assert(formula != NULL);
    assert(num_of_crossroads > 0);
    assert(num_of_streets > 0);
    assert(streets != NULL);

    // ZDE PRIDAT KOD
    int U = num_of_streets;
    // pro kazdy krok
    for (int krok = 0; krok < U; krok++)
    {
        Clause *cl = create_new_clause(formula);
        // existuje alespon jedna ulice ( (from, to) V (from, to) ... V (from, to) )
        for (int y = 0; y < U; y++)
            add_literal_to_clause(cl, true, krok, streets[y].crossroad_from, streets[y].crossroad_to);
    }
}

// Tato funkce by mela do formule pridat klauzule predstavujici podminku 2)
// Křižovatky jsou reprezentovany cisly 0, 1, ..., num_of_crossroads-1
// Cislo num_of_streets predstavuje pocet ulic a proto i pocet kroku cesty
void at_most_one_street_for_each_step(CNF *formula, unsigned num_of_crossroads, unsigned num_of_streets)
{
    assert(formula != NULL);
    assert(num_of_crossroads > 0);
    assert(num_of_streets > 0);

    // ZDE PRIDAT KOD
    int U = num_of_streets;
    int K = num_of_crossroads;
    for (int i = 0; i < U; i++)
    {
        for (int z = 0; z < K; z++)
        {
            for (size_t k = 0; k < K; k++)
            {
                for (size_t z2 = 0; z2 < K; z2++)
                {
                    for (size_t k2 = 0; k2 < K; k2++)
                    {
                        if (z != z2 || k != k2)
                        {
                            Clause *cl = create_new_clause(formula);
                            // 2 rozdilne ulice - neplati (i, z, k) || neplati (i, z2, k2)
                            add_literal_to_clause(cl, 0, i, z, k);
                            add_literal_to_clause(cl, 0, i, z2, k2);
                        }
                    }
                }
            }
        }
    }
}

// Tato funkce by mela do formule pridat klauzule predstavujici podminku 3)
// Křižovatky jsou reprezentovany cisly 0, 1, ..., num_of_crossroads-1
// Cislo num_of_streets predstavuje pocet ulic a proto i pocet kroku cesty
void streets_connected(CNF *formula, unsigned num_of_crossroads, unsigned num_of_streets)
{
    assert(formula != NULL);
    assert(num_of_crossroads > 0);
    assert(num_of_streets > 0);

    // ZDE PRIDAT KOD
    int U = num_of_streets;
    int K = num_of_crossroads;
    for (unsigned i = 0; i < U - 1; i++)
    {
        for (unsigned z = 0; z < K; z++)
        {
            for (unsigned k = 0; k < K; k++)
            {
                Clause *cl = create_new_clause(formula);
                // jestlize neplati (i, z, k), plati v nasledujicim kroku alespon jedna nasledujici krizovatka
                add_literal_to_clause(cl, false, i, z, k);
                for (unsigned kk = 0; kk < K; kk++)
                {
                    add_literal_to_clause(cl, true, i + 1, k, kk);
                }
            }
        }
    }
}

// Tato funkce by mela do formule pridat klauzule predstavujici podminku 4)
// Křižovatky jsou reprezentovany cisly 0, 1, ..., num_of_crossroads-1
// Cislo num_of_streets predstavuje pocet ulic a proto i pocet kroku cesty
void streets_do_not_repeat(CNF *formula, unsigned num_of_crossroads, unsigned num_of_streets)
{
    assert(formula != NULL);
    assert(num_of_crossroads > 0);
    assert(num_of_streets > 0);

    for (unsigned i = 0; i < num_of_streets; ++i)
    {
        // pro kazdy krok i
        for (unsigned j = 0; j < num_of_streets; ++j)
        {
            if (i != j)
            {
                // pro kazdy jiny krok j
                for (unsigned z = 0; z < num_of_crossroads; ++z)
                {
                    for (unsigned k = 0; k < num_of_crossroads; ++k)
                    {
                        // pro kazdu dvojici krizovatek (z, k)
                        Clause *cl = create_new_clause(formula);
                        add_literal_to_clause(cl, false, i, z, k);
                        add_literal_to_clause(cl, false, j, z, k);
                    }
                }
            }
        }
    }
}
