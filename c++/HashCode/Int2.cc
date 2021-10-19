#include <cmath>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <fstream>
#include <iomanip>
#include <iostream>

using namespace std;

#define POPSIZE 100
#define MAXGENS 1000
#define NVARS 3
#define PXOVER 0.8
#define PMUTATION 0.15
//
//  Each GENOTYPE is a member of the population, with
//  gene: a string of variables,
//  fitness: the fitness
//  upper: the variable upper bounds,
//  lower: the variable lower bounds,
//  rfitness: the relative fitness,
//  cfitness: the cumulative fitness.
//
struct genotype {
  double gene[NVARS];
  double fitness;
  double upper[NVARS];
  double lower[NVARS];
  double rfitness;
  double cfitness;
};

struct genotype population[POPSIZE + 1];
struct genotype newpopulation[POPSIZE + 1];

int main();
void crossover(int &seed);
void elitist();
void evaluate();
int i4_uniform_ab(int a, int b, int &seed);
void initialize(string filename, int &seed);
void keep_the_best();
void mutate(int &seed);
double r8_uniform_ab(double a, double b, int &seed);
void report(int generation);
void selector(int &seed);
void timestamp();
void Xover(int one, int two, int &seed);

int main() {
  string filename;
  cin >> filename;
  int generation;
  int i;
  int seed;

  timestamp();
  seed = 123456789;

  initialize(filename, seed);

  evaluate();

  keep_the_best();

  for (generation = 0; generation < MAXGENS; generation++) {
    selector(seed);
    crossover(seed);
    mutate(seed);
    report(generation);
    evaluate();
    elitist();
  }

  cout << "\n";
  cout << "  Best member after " << MAXGENS << " generations:\n";
  cout << "\n";

  for (i = 0; i < NVARS; i++) {
    cout << "  var(" << i << ") = " << population[POPSIZE].gene[i] << "\n";
  }

  cout << "\n";
  cout << "  Best fitness = " << population[POPSIZE].fitness << "\n";
  //
  //  Terminate.
  //
  timestamp();

  return 0;
}
//****************************************************************************80

void crossover(int &seed) {
  const double a = 0.0;
  const double b = 1.0;
  int mem;
  int one;
  int first = 0;
  double x;

  for (mem = 0; mem < POPSIZE; ++mem) {
    x = r8_uniform_ab(a, b, seed);

    if (x < PXOVER) {
      ++first;

      if (first % 2 == 0) {
        Xover(one, mem, seed);
      } else {
        one = mem;
      }
    }
  }
  return;
}

void elitist() {
  int i;
  double best;
  int best_mem;
  double worst;
  int worst_mem;

  best = population[0].fitness;
  worst = population[0].fitness;

  for (i = 0; i < POPSIZE - 1; ++i) {
    if (population[i + 1].fitness < population[i].fitness) {

      if (best <= population[i].fitness) {
        best = population[i].fitness;
        best_mem = i;
      }

      if (population[i + 1].fitness <= worst) {
        worst = population[i + 1].fitness;
        worst_mem = i + 1;
      }

    } else {

      if (population[i].fitness <= worst) {
        worst = population[i].fitness;
        worst_mem = i;
      }

      if (best <= population[i + 1].fitness) {
        best = population[i + 1].fitness;
        best_mem = i + 1;
      }
    }
  }

  if (population[POPSIZE].fitness <= best) {
    for (i = 0; i < NVARS; i++) {
      population[POPSIZE].gene[i] = population[best_mem].gene[i];
    }
    population[POPSIZE].fitness = population[best_mem].fitness;
  } else {
    for (i = 0; i < NVARS; i++) {
      population[worst_mem].gene[i] = population[POPSIZE].gene[i];
    }
    population[worst_mem].fitness = population[POPSIZE].fitness;
  }

  return;
}

void evaluate() {
  int member;
  int i;
  double x[NVARS + 1];

  for (member = 0; member < POPSIZE; member++) {
    for (i = 0; i < NVARS; i++) {
      x[i + 1] = population[member].gene[i];
    }
    vector<vector<pair<int, int>>> vec;
    for (i = 0; i < NVARS; i++) {
    }

    population[member].fitness = (x[1] * x[1]) - (x[1] * x[2]) + x[3];
  }
  return;
}

/* lights diu per cada interseccio l'ordre dels carrers (en numero) i quant
   temps esta cada carrer */
int puntuar(vector<vector<pair<int, int>>> lights) {
  vector<queue<int>> street_end(I); // coches acumulados en cada final de carrer
  vector<bool> can_pass(I, true);   // si pot passar un coche en aquest turn
  vector<int> time_at_end(V, 0);    // segon d'arribada al seguent cruze
  vector<string> car_street(V);     // carrer de cada cotxe
  vector<bool> is_moving(S, false);
  vector<int> cambiar_carrers;
  vector<bool> green(S,
                     false); // diu si el semafor al final del carrer esta verd

  for (int car = 0; car < V; ++car) {
    car_street[car] = routes[car].front();
    routes[car].pop();
  }
  for (vector<pair<int, int>> v : lights) {
    green[v[0].first] = true;
  }

  int puntuacio = 0;

  for (int second = 0; second <= D; ++second) {
    for (int car = 0; car < V; ++car) {
      if (time_at_end[car] == second) {
        street_end[car_street[car]].push(car);
      }
      if (street_end[car_street[car]].front() == car &&
          can_pass[car_street[car]] && green[car_street[car]]) {
        car_street[car] = routes[car].front(); // routes es vqs
        routes[car].pop();
        if (routes[car].empty()) {
          puntuacio += F + D - second;
        }
        time_at_end[car] = second + city[carrer].L;
        can_pass[car_street[car]] = false;
        cambiar_carrers.push_back(car_street[car]);
      }
    }
    for (int k : cambiar_carrers)
      can_pass[k] = true;
    for (vector<pair<int, int>> v : lights) {
      int r = 0;
      for (auto p : v)
        r += p.second;
      int sec2 = second % r;
      if (sec2 == 0) {
        greens[v[0].first] = true;
        greens[v[v.size() - 1].first] = false;
      }
      sec2 -= v[0].second;
      for (int k = 0; k < v.size() && sec2 >= 0; ++k) {
        if (sec2 == 0) {
          greens[v[k].first] = true;
          greens[v[k - 1].first] = false;
        }
        sec2 -= v[k].second;
      }
    }
  }
  return puntuacio;
}

int i4_uniform_ab(int a, int b, int &seed)

//****************************************************************************80
//
//  Purpose:
//
//    I4_UNIFORM_AB returns a scaled pseudorandom I4 between A and B.
//
//  Discussion:
//
//    The pseudorandom number should be uniformly distributed
//    between A and B.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    02 October 2012
//
//  Author:
//
//    John Burkardt
//
//  Reference:
//
//    Paul Bratley, Bennett Fox, Linus Schrage,
//    A Guide to Simulation,
//    Second Edition,
//    Springer, 1987,
//    ISBN: 0387964673,
//    LC: QA76.9.C65.B73.
//
//    Bennett Fox,
//    Algorithm 647:
//    Implementation and Relative Efficiency of Quasirandom
//    Sequence Generators,
//    ACM Transactions on Mathematical Software,
//    Volume 12, Number 4, December 1986, pages 362-376.
//
//    Pierre L'Ecuyer,
//    Random Number Generation,
//    in Handbook of Simulation,
//    edited by Jerry Banks,
//    Wiley, 1998,
//    ISBN: 0471134031,
//    LC: T57.62.H37.
//
//    Peter Lewis, Allen Goodman, James Miller,
//    A Pseudo-Random Number Generator for the System/360,
//    IBM Systems Journal,
//    Volume 8, Number 2, 1969, pages 136-143.
//
//  Parameters:
//
//    Input, int A, B, the limits of the interval.
//
//    Input/output, int &SEED, the "seed" value, which should NOT be 0.
//    On output, SEED has been updated.
//
//    Output, int I4_UNIFORM, a number between A and B.
//
{
  int c;
  const int i4_huge = 2147483647;
  int k;
  float r;
  int value;

  if (seed == 0) {
    cerr << "\n";
    cerr << "I4_UNIFORM_AB - Fatal error!\n";
    cerr << "  Input value of SEED = 0.\n";
    exit(1);
  }
  //
  //  Guarantee A <= B.
  //
  if (b < a) {
    c = a;
    a = b;
    b = c;
  }

  k = seed / 127773;

  seed = 16807 * (seed - k * 127773) - k * 2836;

  if (seed < 0) {
    seed = seed + i4_huge;
  }

  r = (float)(seed)*4.656612875E-10;
  //
  //  Scale R to lie between A-0.5 and B+0.5.
  //
  r = (1.0 - r) * ((float)a - 0.5) + r * ((float)b + 0.5);
  //
  //  Use rounding to convert R to an integer between A and B.
  //
  value = round(r);
  //
  //  Guarantee A <= VALUE <= B.
  //
  if (value < a) {
    value = a;
  }
  if (b < value) {
    value = b;
  }

  return value;
}
//****************************************************************************80

void initialize(string filename, int &seed)

//****************************************************************************80
//
//  Purpose:
//
//    INITIALIZE initializes the genes within the variables bounds.
//
//  Discussion:
//
//    It also initializes (to zero) all fitness values for each
//    member of the population. It reads upper and lower bounds
//    of each variable from the input file `gadata.txt'. It
//    randomly generates values between these bounds for each
//    gene of each genotype in the population. The format of
//    the input file `gadata.txt' is
//
//      var1_lower_bound var1_upper bound
//      var2_lower_bound var2_upper bound ...
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    28 April 2014
//
//  Author:
//
//    Original version by Dennis Cormier and Sita Raghavan.
//    This C++ version by John Burkardt.
//
//  Parameters:
//
//    Input, string FILENAME, the name of the input file.
//
//    Input/output, int &SEED, a seed for the random number generator.
//
{
  int i;
  ifstream input;
  int j;
  double lbound;
  double ubound;

  input.open(filename.c_str());

  if (!input) {
    cerr << "\n";
    cerr << "INITIALIZE - Fatal error!\n";
    cerr << "  Cannot open the input file!\n";
    exit(1);
  }
  //
  //  Initialize variables within the bounds
  //
  for (i = 0; i < NVARS; i++) {
    input >> lbound >> ubound;

    for (j = 0; j < POPSIZE; j++) {
      population[j].fitness = 0;
      population[j].rfitness = 0;
      population[j].cfitness = 0;
      population[j].lower[i] = lbound;
      population[j].upper[i] = ubound;
      population[j].gene[i] = r8_uniform_ab(lbound, ubound, seed);
    }
  }

  input.close();

  return;
}
//****************************************************************************80

void keep_the_best()

//****************************************************************************80
//
//  Purpose:
//
//    KEEP_THE_BEST keeps track of the best member of the population.
//
//  Discussion:
//
//    Note that the last entry in the array Population holds a
//    copy of the best individual.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    29 December 2007
//
//  Author:
//
//    Original version by Dennis Cormier and Sita Raghavan.
//    This C++ version by John Burkardt.
//
//  Local parameters:
//
//    Local, int CUR_BEST, the index of the best individual.
//
{
  int cur_best;
  int mem;
  int i;

  cur_best = 0;

  for (mem = 0; mem < POPSIZE; mem++) {
    if (population[POPSIZE].fitness < population[mem].fitness) {
      cur_best = mem;
      population[POPSIZE].fitness = population[mem].fitness;
    }
  }
  //
  //  Once the best member in the population is found, copy the genes.
  //
  for (i = 0; i < NVARS; i++) {
    population[POPSIZE].gene[i] = population[cur_best].gene[i];
  }

  return;
}
//****************************************************************************80

void mutate(int &seed)

//****************************************************************************80
//
//  Purpose:
//
//    MUTATE performs a random uniform mutation.
//
//  Discussion:
//
//    A variable selected for mutation is replaced by a random value
//    between the lower and upper bounds of this variable.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    28 April 2014
//
//  Author:
//
//    Original version by Dennis Cormier and Sita Raghavan.
//    This C++ version by John Burkardt.
//
//  Parameters:
//
//    Input/output, int &SEED, a seed for the random number generator.
//
{
  const double a = 0.0;
  const double b = 1.0;
  int i;
  int j;
  double lbound;
  double ubound;
  double x;

  for (i = 0; i < POPSIZE; i++) {
    for (j = 0; j < NVARS; j++) {
      x = r8_uniform_ab(a, b, seed);
      if (x < PMUTATION) {
        lbound = population[i].lower[j];
        ubound = population[i].upper[j];
        population[i].gene[j] = r8_uniform_ab(lbound, ubound, seed);
      }
    }
  }

  return;
}
//****************************************************************************80

double r8_uniform_ab(double a, double b, int &seed)

//****************************************************************************80
//
//  Purpose:
//
//    R8_UNIFORM_AB returns a scaled pseudorandom R8.
//
//  Discussion:
//
//    The pseudorandom number should be uniformly distributed
//    between A and B.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    09 April 2012
//
//  Author:
//
//    John Burkardt
//
//  Parameters:
//
//    Input, double A, B, the limits of the interval.
//
//    Input/output, int &SEED, the "seed" value, which should NOT be 0.
//    On output, SEED has been updated.
//
//    Output, double R8_UNIFORM_AB, a number strictly between A and B.
//
{
  int i4_huge = 2147483647;
  int k;
  double value;

  if (seed == 0) {
    cerr << "\n";
    cerr << "R8_UNIFORM_AB - Fatal error!\n";
    cerr << "  Input value of SEED = 0.\n";
    exit(1);
  }

  k = seed / 127773;

  seed = 16807 * (seed - k * 127773) - k * 2836;

  if (seed < 0) {
    seed = seed + i4_huge;
  }

  value = (double)(seed)*4.656612875E-10;

  value = a + (b - a) * value;

  return value;
}
//****************************************************************************80

void report(int generation)

//****************************************************************************80
//
//  Purpose:
//
//    REPORT reports progress of the simulation.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    29 December 2007
//
//  Author:
//
//    Original version by Dennis Cormier and Sita Raghavan.
//    This C++ version by John Burkardt.
//
//  Local parameters:
//
//    Local, double avg, the average population fitness.
//
//    Local, best_val, the best population fitness.
//
//    Local, double square_sum, square of sum for std calc.
//
//    Local, double stddev, standard deviation of population fitness.
//
//    Local, double sum, the total population fitness.
//
//    Local, double sum_square, sum of squares for std calc.
//
{
  double avg;
  double best_val;
  int i;
  double square_sum;
  double stddev;
  double sum;
  double sum_square;

  if (generation == 0) {
    cout << "\n";
    cout << "  Generation       Best            Average       Standard \n";
    cout << "  number           value           fitness       deviation \n";
    cout << "\n";
  }

  sum = 0.0;
  sum_square = 0.0;

  for (i = 0; i < POPSIZE; i++) {
    sum = sum + population[i].fitness;
    sum_square = sum_square + population[i].fitness * population[i].fitness;
  }

  avg = sum / (double)POPSIZE;
  square_sum = avg * avg * POPSIZE;
  stddev = sqrt((sum_square - square_sum) / (POPSIZE - 1));
  best_val = population[POPSIZE].fitness;

  cout << "  " << setw(8) << generation << "  " << setw(14) << best_val << "  "
       << setw(14) << avg << "  " << setw(14) << stddev << "\n";

  return;
}
//****************************************************************************80

void selector(int &seed)

//****************************************************************************80
//
//  Purpose:
//
//    SELECTOR is the selection function.
//
//  Discussion:
//
//    Standard proportional selection for maximization problems incorporating
//    the elitist model.  This makes sure that the best member always survives.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    28 April 2014
//
//  Author:
//
//    Original version by Dennis Cormier and Sita Raghavan.
//    This C++ version by John Burkardt.
//
//  Parameters:
//
//    Input/output, int &SEED, a seed for the random number generator.
//
{
  const double a = 0.0;
  const double b = 1.0;
  int i;
  int j;
  int mem;
  double p;
  double sum;
  //
  //  Find the total fitness of the population.
  //
  sum = 0.0;
  for (mem = 0; mem < POPSIZE; mem++) {
    sum = sum + population[mem].fitness;
  }
  //
  //  Calculate the relative fitness of each member.
  //
  for (mem = 0; mem < POPSIZE; mem++) {
    population[mem].rfitness = population[mem].fitness / sum;
  }
  //
  //  Calculate the cumulative fitness.
  //
  population[0].cfitness = population[0].rfitness;
  for (mem = 1; mem < POPSIZE; mem++) {
    population[mem].cfitness =
        population[mem - 1].cfitness + population[mem].rfitness;
  }
  //
  //  Select survivors using cumulative fitness.
  //
  for (i = 0; i < POPSIZE; i++) {
    p = r8_uniform_ab(a, b, seed);
    if (p < population[0].cfitness) {
      newpopulation[i] = population[0];
    } else {
      for (j = 0; j < POPSIZE; j++) {
        if (population[j].cfitness <= p && p < population[j + 1].cfitness) {
          newpopulation[i] = population[j + 1];
        }
      }
    }
  }
  //
  //  Overwrite the old population with the new one.
  //
  for (i = 0; i < POPSIZE; i++) {
    population[i] = newpopulation[i];
  }

  return;
}
//****************************************************************************80

void timestamp()

//****************************************************************************80
//
//  Purpose:
//
//    TIMESTAMP prints the current YMDHMS date as a time stamp.
//
//  Example:
//
//    May 31 2001 09:45:54 AM
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    04 October 2003
//
//  Author:
//
//    John Burkardt
//
{
#define TIME_SIZE 40

  static char time_buffer[TIME_SIZE];
  const struct tm *tm;
  time_t now;

  now = time(NULL);
  tm = localtime(&now);

  strftime(time_buffer, TIME_SIZE, "%d %B %Y %I:%M:%S %p", tm);

  cout << time_buffer << "\n";

  return;
#undef TIME_SIZE
}
//****************************************************************************80

void Xover(int one, int two, int &seed)

//****************************************************************************80
//
//  Purpose:
//
//    XOVER performs crossover of the two selected parents.
//
//  Licensing:
//
//    This code is distributed under the GNU LGPL license.
//
//  Modified:
//
//    28 April 2014
//
//  Author:
//
//    Original version by Dennis Cormier and Sita Raghavan.
//    This C++ version by John Burkardt.
//
//  Local parameters:
//
//    Local, int point, the crossover point.
//
//  Parameters:
//
//    Input, int ONE, TWO, the indices of the two parents.
//
//    Input/output, int &SEED, a seed for the random number generator.
//
{
  int i;
  int point;
  double t;
  //
  //  Select the crossover point.
  //
  point = i4_uniform_ab(0, NVARS - 1, seed);
  //
  //  Swap genes in positions 0 through POINT-1.
  //
  for (i = 0; i < point; i++) {
    t = population[one].gene[i];
    population[one].gene[i] = population[two].gene[i];
    population[two].gene[i] = t;
  }

  return;
}
