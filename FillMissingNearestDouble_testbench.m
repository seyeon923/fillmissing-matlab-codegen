function FillMissingNearestDouble_TestBench()
    x = [1.,2.,nan; 4.,5.,6.]
    y = FillMissingNearestDouble(x, 'nearest')

    x = [1.,2.,3.;4.,nan,5.;6.,7.,8.]
    y = FillMissingNearestDouble(x, 'nearest')
end
