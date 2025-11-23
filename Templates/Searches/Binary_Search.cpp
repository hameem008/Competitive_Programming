ll hi, lo, mid;
while (hi - lo > 1) // FFFFTTT find first true
{
    mid = (hi + lo) / 2;
    if (pf(mid))
        hi = mid;
    else
        lo = mid + 1;
}
if (pf(lo))
    cout << lo << endl;
else
    cout << hi << endl;
while (hi - lo > 1) // TTTTFFF find last true
{
    mid = (hi + lo) / 2;
    if (pf(mid))
        lo = mid;
    else
        hi = mid - 1;
}
if (pf(hi))
    cout << hi << endl;
else
    cout << lo << endl;