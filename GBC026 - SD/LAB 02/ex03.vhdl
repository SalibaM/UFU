library ieee;
use ieee.std_logic_1164.all;

entity CombinedSystem is
  port (
    a, b, c, d : in std_logic;
    s0, s1, s2, s : out std_logic
  );
end entity CombinedSystem;

architecture combined_architecture of CombinedSystem is
  component numOnes
    port (
      a, b, c, d : in std_logic;
      s0, s1, s2 : out std_logic
    );
  end component;
  component parityEven
    port (
      a, b, c, d : in std_logic;
      s : out std_logic
    );
  end component;

signal s0_numOnes, s1_numOnes, s2_numOnes, s_parityEven :
std_logic;
begin
  numOnes_inst : numOnes
  port map (
    a => a,
    b => b,
    c => c,
    d => d,
    s0 => s0_numOnes,
    s1 => s1_numOnes,
    s2 => s2_numOnes
    );
  parityEven_inst : parityEven
  port map (
    a => a,
    b => b,
    c => c,
    d => d,
    s => s_parityEven
    );
  s0 <= s0_numOnes;
  s1 <= s1_numOnes;
  s2 <= s2_numOnes;
  s <= s_parityEven;
end architecture combined_architecture;
