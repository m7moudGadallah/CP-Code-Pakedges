#include <bits/stdc++.h>

using namespace std;

/* Primes class
    :this class deals with prime numbers

    methods:
        - divisors: get number of divisors of number x
        - primality: check if number n is prime or not
        - sieve: find primes using  Sieve of Eratosthenes Algorithm
        - sieveFactoriaze: find primes in range from (1 --> n) using  Sieve of Eratosthenes Algorithm
        - primeFactorization: find all prime factors of number x
*/

class Primes {
public:
    /*divisors
        summary: get number of divisors of number x
        pre: passing an integer number
        post: return number of divisors of this number
        Time Complexity: O(sqrt(n))
    */
    static int divisors(int n) {
        int cnt{0};

        for (int i = 1; i * i < n; ++i) {
            if (n % i == 0) {
                cnt += 2;
            }

            cnt -= (i * i == n);
        }

        return cnt;
    }


    /*primality
        summary: check if number n is prime or not
        pre: passing an integer number
        post: return true if number is prime other wise false
        Time Complexity: O(sqrt(n))
    */
    static bool primality(int n) {
        for (int i = 2; i * i <= n; ++i) {
            if (n % i == 0) {
                return false;
            }
        }

        return (n > 1);
    }


    /*sieve
        summary: find primes in range from (1 --> n) using  Sieve of Eratosthenes Algorithm 
        pre: passing an integer number
        post: return vector it's size is n + 1 contains indices(0 --> n) and each index contains true (for primes) and false (for composite)
        Time Complexity: O(n * log(log(n)))
    */
    static vector<bool> sieve(int n) {
        vector<bool> isPrime(n + 1, true);

        isPrime[0] = isPrime[1] = false;

        for (int i = 2; i * i <= n; ++i) {
            if (isPrime[i]) {
                for (int k = i * i; k <= n; k += i) {
                    isPrime[k] = false;
                }
            }
        }

        return isPrime;
    }


    /*sieveFactoriaze
        summary: find smallest prime divisor of each number in range from (1 --> n) using Sieve of Eratosthenes Algorithm 
        pre: passing an integer number
        post: return vector it's size is n + 1 contains indices(0 --> n) and each index contains -1 for (0 & 1) &
                                                                                                 0 (for primes) &
                                                                                                 smallest prime devisor of number (for composite number)
        Time Complexity: O(n * log(log(n)))
    */
    static vector<int> sieveFactoriaze(int n) {
        vector<int> mnPrimeFact(n + 1);

        mnPrimeFact[0] = mnPrimeFact[1] = -1;

        for (int i = 2; i * i <= n; ++i) {
            if (!mnPrimeFact[i]) {
                for (int k = i * i; k <= n; k += i) {
                    if (!mnPrimeFact[k]) {
                        mnPrimeFact[k] = i;
                    }
                }
            }
        }

        return mnPrimeFact;
    }

    /*primeFactorization
        summary: find all prime factors of number x
        pre: passing an integer number (x) and sieveFactoriaze vector (F) 
        post: return vector of prime factorization of this number
        Time Complexity: O(log X)
    */
    static vector<int> primeFactorization(int x, vector<int> F) {
        vector<int> primeFact;

        while (F[x] > 0) {
            primeFact.emplace_back(F[x]);

            x /= F[x];
        }

        primeFact.emplace_back(x);

        return primeFact;
    }
};