library ieee; 
use ieee.std.logic_1164.all;

entity somador is
  port (
    A, B : in std_logic_vector(3 downto 0);
    Soma : out std_logic_vector(3 downto 0);
    Carry : out std_logic
  );
end entity somador;
  

architecture a_s of somador is
  signal C0, C1, C2, C3 : std_logic;
  signal S0, S1, S2, S3 : std_logic;
begin
  U1: entity work.B1 port map (a0 => A(0), b0 => B(0), c0 => '0', S1 => S0, C1 => C0);
  U2: entity work.B1 port map (a0 => A(1), b0 => B(1), c0 => C0, S1 => S1, C1 => C1);
  U3: entity work.B1 port map (a0 => A(2), b0 => B(2), c0 => C1, S1 => S2, C1 => C2);
  U4: entity work.B1 port map (a0 => A(3), b0 => B(3), c0 => C2, S1 => S3, C1 => C3);
  Soma <= S3 & S2 & S1 & S0;
  Carry <= C3;
end architecture a_s;
