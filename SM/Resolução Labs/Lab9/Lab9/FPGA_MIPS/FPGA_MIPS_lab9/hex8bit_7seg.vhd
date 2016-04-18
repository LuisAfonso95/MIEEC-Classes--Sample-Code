-- hex8bit_7seg
-- takes 8 bit value and converts to two 7seg digits 
-- jlobo May 2009

LIBRARY IEEE;
USE IEEE.STD_LOGIC_1164.all;
USE  IEEE.STD_LOGIC_ARITH.all;
USE  IEEE.STD_LOGIC_UNSIGNED.all;

-- Hexadecimal to 7 Segment Decoder for LED Display

ENTITY hex8bit_7seg IS
	
	PORT( hex_8bit	: IN	STD_LOGIC_VECTOR(7 downto 0);
	      HEX0		: OUT   STD_LOGIC_VECTOR(6 downto 0);
	      HEX1		: OUT	STD_LOGIC_VECTOR(6 downto 0) );

END hex8bit_7seg;

ARCHITECTURE a OF hex8bit_7seg IS

COMPONENT hex4bit_7seg
		PORT( hex_4bit	: IN	STD_LOGIC_VECTOR(3 downto 0);
	          HEX0		: OUT	STD_LOGIC_VECTOR(6 downto 0) );
END COMPONENT;

BEGIN
	hex4bit_0: hex4bit_7seg port map (hex_8bit(3 downto 0),HEX0);
	hex4bit_1: hex4bit_7seg port map (hex_8bit(7 downto 4),HEX1);
END a;

