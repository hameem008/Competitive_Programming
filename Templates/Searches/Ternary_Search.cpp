lld lo, hi;
while (hi - lo > 1e-7) // finding minimum
{
    lld mid1 = lo + (hi - lo) / 3, mid2 = hi - (hi - lo) / 3;
    lld ans1 = fun(mid1), ans2 = fun(mid2);
    if (ans1 < ans2)
        hi = mid2;
    else if (ans1 > ans2)
        lo = mid1;
    else
    {
        hi = mid2;
        lo = mid1;
    }
}
while (hi - lo > 1e-7) // finding maximum
{
    lld mid1 = lo + (hi - lo) / 3, mid2 = hi - (hi - lo) / 3;
    lld ans1 = fun(mid1), ans2 = fun(mid2);
    if (ans1 < ans2)
        lo = mid1;
    else if (ans1 > ans2)
        hi = mid2;
    else
    {
        hi = mid2;
        lo = mid1;
    }
}