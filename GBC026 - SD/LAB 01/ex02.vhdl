library ieee; 
use ieee.std.logic_1164.all;

entity expressao is
  port (
    A, B, C : in std_logic;
    S : out std_logic
  );
end entity expressao;

architecture A_expressao of expressao is
begin
  S<=((A nor B) nor ((B nor B) nor C);
end architecture A_expressao;
