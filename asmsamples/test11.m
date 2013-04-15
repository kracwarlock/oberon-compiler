MODULE TEST;
IMPORT In, Out;

TYPE
  y = INTEGER;

VAR 
  i, n, allsum, ans : y;

PROCEDURE SumFn(a, b, c : INTEGER) : INTEGER;
BEGIN
    c := 0;
    WHILE a <= b DO
      c := c + a;
      a := a + 1;
    END;
    RETURN c;
END SumFn;

BEGIN
  i := 0;
  n := 100;
  ans := 0;
  allsum := SumFn(i, n, ans);
END TEST.