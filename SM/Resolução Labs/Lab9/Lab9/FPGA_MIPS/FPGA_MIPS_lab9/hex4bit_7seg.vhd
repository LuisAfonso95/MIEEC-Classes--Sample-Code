-- hex4bit_7seg
-- takes 4 bit hex value and converts to 7seg digit 
-- jlobo May 2009

LIBRARY IEEE;
USE IEEE.STD_LOGIC_1164.all;
USE  IEEE.STD_LOGIC_ARITH.all;
USE  IEEE.STD_LOGIC_UNSIGNED.all;

-- Hexadecimal to 7 Segment Decoder for LED Display

ENTITY hex4bit_7seg IS
	
	PORT( hex_4bit	: IN	STD_LOGIC_VECTOR(3 downto 0);
	      HEX0		: OUT	STD_LOGIC_VECTOR(6 downto 0) );

END hex4bit_7seg;

ARCHITECTURE a OF hex4bit_7seg IS

BEGIN
		with hex_4bit select
		HEX0<= 	"1000000" when "0000",
				"1111001" when "0001",
				"0100100" when "0010",
				"0110000" when "0011",
				"0011001" when "0100",
				"0010010" when "0101",
				"0000010" when "0110",
				"1111000" when "0111",
				"0000000" when "1000",
				"0010000" when "1001",
				"0100000" when "1010",
				"0000011" when "1011",
				"1000110" when "1100",
				"0100001" when "1101",
				"0000100" when "1110",
				"0001110" when "1111";
END a;

