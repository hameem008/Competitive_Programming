const ll N = 1e7 + 1;
vector<bool> isPrime(N, true);
vector<ll> allPrimes;
vector<ll> lowestPrimeFactorOf(N, 0);
vector<ll> highestPrimeFactorOf(N, 0);
void calculateSieve()
{
    isPrime[0] = isPrime[1] = false;
    for (int i = 2; i < N; i++)
    {
        if (isPrime[i])
        {
            highestPrimeFactorOf[i] = lowestPrimeFactorOf[i] = i;
            for (int j = 2 * i; j < N; j += i)
            {
                isPrime[j] = false;
                highestPrimeFactorOf[j] = i;
                if (lowestPrimeFactorOf[j] == 0)
                    lowestPrimeFactorOf[j] = i;
            }
        }
    }
    for (int i = 0; i < N; i++)
    {
        if (isPrime[i])
            allPrimes.push_back(i);
    }
}
vector<ll> getPrimeFactorsOf(ll n)
{
    vector<ll> distinctPrimeFactors;
    vector<ll> primeFactors;
    // if max_element <= 1e7 then use this snippet where N = 1e7 + 1
    while (n > 1)
    {
        ll pf = lowestPrimeFactorOf[n];
        distinctPrimeFactors.push_back(pf);
        while (n % pf == 0)
        {
            primeFactors.push_back(pf);
            n /= pf;
        }
    }
    return distinctPrimeFactors;
    // if max_element <= 1e9 then use this snippet where N = 31625
    // for (int i = 0; i < allPrimes.size(); i++)
    // {
    //     ll pf = allPrimes[i];
    //     if (n % pf == 0)
    //     {
    //         distinctPrimeFactors.push_back(pf);
    //         while (n % pf == 0)
    //         {
    //             primeFactors.push_back(pf);
    //             n /= pf;
    //         }
    //     }
    //     else if (n < pf)
    //         break;
    // }
    // if (n != 1)
    // {
    //     distinctPrimeFactors.push_back(n);
    //     primeFactors.push_back(n);
    // }
    // return distinctPrimeFactors;
}