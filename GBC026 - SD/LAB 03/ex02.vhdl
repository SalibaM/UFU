library ieee; 
use ieee.std.logic_1164.all;

entity Z1 is
  port (
    an, bn, cn : in std_logic;
    Sn, Cn1 : out std_logic
  );
end entity Z1;
  
architecture A_Z1 of Z1 is
begin
  Sn <= (an xor bn xor cn);
  Cn1 <= ((bn and cn) or (an and cn) or (an and bn));
end architecture A_Z1;
