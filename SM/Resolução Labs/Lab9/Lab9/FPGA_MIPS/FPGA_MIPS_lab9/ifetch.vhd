--
--
-- Ifetch module (provides the PC and instruction memory for the SPIM computer)
--
-- Copyright (c) 1996 J. Hamblen, Georgia Tech, School of ECE, Atlanta, GA
--
-- jlobo Abr2008: added 8 more constants for longer machine code program
--
library IEEE;
use IEEE.STD_LOGIC_1164.all;
use IEEE.STD_LOGIC_ARITH.all;
use IEEE.STD_LOGIC_UNSIGNED.all;

entity Ifetch is

        port(signal Instruction : out std_logic_vector(31 downto 0);
        signal PCadd : out  std_logic_vector(7 downto 0);
        signal Addresult : in std_logic_vector(7 downto 0);
        signal Branch : in std_logic;
        signal clock, reset : in std_logic;
        signal Zero : in std_logic;
        signal PCout : out std_logic_vector(7 downto 0));

end Ifetch;

--
-- Ifetch architecture
--

architecture behavior of Ifetch is


          signal PC : std_logic_vector(7 downto 0);
          signal PCtemp : std_logic_vector(7 downto 0);
          signal PCaddtemp : std_logic_vector(8 downto 0);
-- Insert SPIM Machine Language Test Program Here
          constant mem0 : std_logic_vector(31 downto 0) := (
--          Field   | op | rs | rt | rd ?addr/immed|
To_Stdlogicvector(B"10001100000000100000000000000000")); -- lw $2,0($0)
          constant mem1 : std_logic_vector(31 downto 0) := (
To_Stdlogicvector(B"10001100000000110000000000000001")); -- lw $3,1($0)
          constant mem2 : std_logic_vector(31 downto 0) := (
To_Stdlogicvector(B"00000000010000110000100000100000")); -- add $1,$2,$3
          constant mem3 : std_logic_vector(31 downto 0) := (
To_Stdlogicvector(B"10101100000000010000000000000011")); -- sw $1,3($0)
          constant mem4 : std_logic_vector(31 downto 0) := (
To_Stdlogicvector(B"00010000001000101111111111111111")); -- beq $1,$2,-1
          constant mem5 : std_logic_vector(31 downto 0) := (
To_Stdlogicvector(B"00010000001000011111111111111010")); -- beq $1,$1,-6
          constant mem6 : std_logic_vector(31 downto 0) := (
To_Stdlogicvector(B"00000000000000000000000000000000")); -- nop                                   
          constant mem7 : std_logic_vector(31 downto 0) := (
To_Stdlogicvector(B"00000000000000000000000000000000")); -- nop          
                                
          constant mem8 : std_logic_vector(31 downto 0) := (
To_Stdlogicvector(X"00000000")); -- nop    
          constant mem9 : std_logic_vector(31 downto 0) := (
To_Stdlogicvector(X"00000000")); -- nop  
          constant memA : std_logic_vector(31 downto 0) := (
To_Stdlogicvector(X"00000000")); -- nop  
          constant memB : std_logic_vector(31 downto 0) := (
To_Stdlogicvector(X"00000000")); -- nop  
          constant memC : std_logic_vector(31 downto 0) := (
To_Stdlogicvector(X"00000000")); -- nop  
          constant memD : std_logic_vector(31 downto 0) := (
To_Stdlogicvector(X"00000000")); -- nop  
          constant memE : std_logic_vector(31 downto 0) := (
To_Stdlogicvector(X"00000000")); -- nop  
          constant memF : std_logic_vector(31 downto 0) := (
To_Stdlogicvector(X"00000000")); -- nop  

	begin
-- Increment PC by 4        
	PCout <= PC;
        PCaddtemp(7 downto 2) <= PC(7 downto 2) + CONV_STD_LOGIC_VECTOR(1,6);
        PCaddtemp(1 downto 0)<= CONV_STD_LOGIC_VECTOR(0,2);
        PCadd <= PCaddtemp(7 downto 0);
-- Mux for Branch Address or Next Address        
	PCtemp <= Addresult WHEN ((Branch='1') AND (Zero='1')) 
	ELSE PCaddtemp(7 downto 0);
-- Load next PC
        PROCESS
        Begin
        Wait Until (clock'event) and (clock='1');
          If reset='1' then
          PC<=To_Stdlogicvector(X"00"); else PC<=PCtemp;
          end if;
        end process;

-- Fetch Instruction from memory     
          Process (PC)
          begin
          case PC(5 downto 2) is          
           WHEN "0000" => instruction <= mem0;
           WHEN "0001" => instruction <= mem1;
           WHEN "0010" => instruction <= mem2;
           WHEN "0011" => instruction <= mem3;
           WHEN "0100" => instruction <= mem4;
           WHEN "0101" => instruction <= mem5;
           WHEN "0110" => instruction <= mem6;
           when "0111" => instruction <= mem7;
           WHEN "1000" => instruction <= mem8;
           WHEN "1001" => instruction <= mem9;
           WHEN "1010" => instruction <= memA;
           WHEN "1011" => instruction <= memB;
           WHEN "1100" => instruction <= memC;
           WHEN "1101" => instruction <= memD;
           WHEN "1110" => instruction <= memE;
           when "1111" => instruction <= memF;
           when others => instruction <= To_stdlogicvector(X"00000000");
          end case;
          end process;

end behavior;

