MODULE TEST;
IMPORT In, Out;

TYPE
  y = INTEGER;

VAR 
  v1, v2, n, iter, aux1, ol, o1 : y;

PROCEDURE Main22(ro , olp : INTEGER) : INTEGER ;
VAR root : y;
BEGIN
      ro := olp;
      ro := 15;
      RETURN ro;
END Main22;

BEGIN
  v1 := 0;
  v2 := 1;
  ol := 0;
  o1 := 0;
  ol := Main22(ol+o1,o1+ol);
END TEST.