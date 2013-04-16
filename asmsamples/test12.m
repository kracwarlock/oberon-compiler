MODULE TEST;
IMPORT In, Out;

TYPE
  y = INTEGER;

VAR 
  i, n, allsum, ans : y;

PROCEDURE SumFn(a, b, c : INTEGER) : INTEGER;
  PROCEDURE DoubleIt(p : INTEGER) : INTEGER;
  BEGIN
    p := p + p;
    RETURN p;
  END DoubleIt;
BEGIN
    c := 0;
    WHILE a <= b DO
      c := c + a;
      a := a + 1;
    END;
    c := DoubleIt(c);
    RETURN c;
END SumFn;

BEGIN
  i := 0;
  n := 10;
  ans := 0;
  allsum := SumFn(i, n, ans);
END TEST.