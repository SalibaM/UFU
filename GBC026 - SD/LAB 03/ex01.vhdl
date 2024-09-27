library ieee;
use ieee.std.logic_1164.all;

entity B1 is
  port (
    a0, b0 : in std_logic;
    S0, C1 : out std_logic
  );
end entity B1;
  
architecture A_B1 of B1 is
begin
  S0 <= (a0 xor b0);
  C1 <= (a0 and b0);
end architecture A_B1;
