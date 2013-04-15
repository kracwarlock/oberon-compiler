MODULE TEST;
IMPORT In, Out;

TYPE
  y = INTEGER;

VAR 
  v1, v2, n, iter, aux1 : y;

BEGIN
  v1 := 0;
  v2 := 1;
  iter := 3;
  n := 10;
  aux1 := 1;
  WHILE iter <= n DO
        iter := iter + 1;
        aux1 := v2;
        v2 := v1 + v2;
        v1 := aux1;
  END;
  v2 := v2;
END TEST.