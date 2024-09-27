--subsistema numOnes
library ieee;
use ieee.std_logic_1164.all;

entity numOnes is
  port ( 
    a, b, c, d : in std_logic;
    s0, s1, s2 : out std_logic
  );
end entity parityEven;

architecture a_no of numOnes is
begin
  s2 <= (a and b and c and d);
  s1 <= (not a and not b and c and d) or (not a and b and not c and d) or (not a and b and c and not d) or (not a and b and c and d) or (a and not b and not c and d) or (a and not b and c and not d) or (a and not b and c and d) or (a and b and not c and not d) or (a and b and c and not d) or (a and b and c and not d);
  s0 <= (not a and not b and not c and d) or (not a and not b and c and not d) or (not a and b and not c and not d) or (not a and b and c and d) or (a and not b and c and d) or (a and b and not c and d) or (a and b and c and not d) or (a and b and c and d);
end architecture a_no;
