--subsistema parityEven
library ieee; 
use ieee.std_logic_1164.all;

entity parityEven is
  port ( 
    a,b,c,d : in std_logic;
    s : out std_logic
  );
end entity parityEven;

architecture a_pe of parityEven is
begin
  s <= (((a xor b) xor c) xor d);
end architecture a_pe;
