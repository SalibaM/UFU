library ieee; 
use ieee.std.logic_1164.all;

entity portaE is
  port ( 
    A, B : in std_logic;
    S : out std_logic
  );
end entity portaE;

architecture A_portaE of portaE is
begin
  S <= ((A nand B) nand (A nand B));
end architecture A_portaE;
