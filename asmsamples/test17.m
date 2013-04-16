MODULE LTESQ;
IMPORT In, Out;

TYPE
  y = INTEGER;

VAR 
  v1 : ARRAY 10 OF INTEGER;
  v2: INTEGER;
  i,j,a,b: INTEGER;

BEGIN
  i := 1;
  WHILE i < 11 DO
  	v1[i] := i;
  	i := i + 1;
  END;
  i := 1;
  WHILE i < 11 DO
  	WHILE j <= i DO
  		a := v1[i];
  		b := v1[j];
  		IF a <= b THEN
  			v1[i] := b;
  			v1[j] := a;
  		END;
  	END;
  END;
END LTESQ.