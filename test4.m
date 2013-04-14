MODULE LTESQ;
IMPORT In, Out;

TYPE
  y = INTEGER;

VAR 
  v1,v2,v3 : y;

BEGIN
  v1 := 3;
  v2 := 8;
  v3 := 0;
  IF v1 <= v2 THEN
    IF v2 <= v3 THEN
      v3 := 16;
    ELSE
      v3 := 100;
    END;
  ELSE
    v3 := 20;
  END;
END LTESQ.