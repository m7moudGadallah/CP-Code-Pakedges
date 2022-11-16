# Math

<p>

## [Primes](Primes.cpp)
- this class deals with numbers specially primes numbers

### Methods
#### divisors
***summary:*** get number of divisors of number x
***pre:*** passing an integer number
***post:*** return number of divisors of this number
***Time Complexity:*** O(sqrt(n))

#### primality
***summary:*** check if number n is prime or not
***pre:*** passing an integer number
***post:*** return true if number is prime other wise false
***Time Complexity:*** O(sqrt(n))

#### sieve
***summary:*** find primes using  Sieve of Eratosthenes Algorithm 
***pre:*** passing an integer number
***post:*** return vector it's size is n + 1 contains indices(0 --> n) and each index contains true (for primes) and false (for composite)
***Time Complexity:*** O(n * log(log(n)))

#### sieveFactoriaze
***summary:*** find smallest prime divisor of each number in range from (1 --> n) using Sieve of Eratosthenes Algorithm 
***pre:*** passing an integer number
***post:*** return vector it's size is n + 1 contains indices(0 --> n) and each index contains `-1 for (0 & 1)` & `0 (for primes)` & `smallest prime devisor of number (for composite number)`
***Time Complexity:*** O(n * log(log(n)))
    
#### primeFactorization
***summary:*** find all prime factors of number x
***pre:*** passing an integer number (x) and sieveFactoriaze vector (F) 
***post:*** return vector of prime factorization of this number
Time Complexity: O(log X)

</p>