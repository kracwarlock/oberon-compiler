MODULE LTESQ;
IMPORT In, Out;

TYPE
  y = INTEGER;

VAR 
  ans,i : y;

BEGIN
  ans := 0;
  i := 0;
  FOR i := 0 TO 10 BY 1 DO
    ans := ans + i;
  END;
END LTESQ.