#ifndef BITWISE_H
# define BITWISE_H

/*
** Allowed headers.
*/
# include <stdint.h>

/*
** Macro definitions.
*/
# define NTOBIN(x, y)	_Generic((x),	uint8_t:	uint8_tobin,	\
										uint16_t:	uint16_tobin,	\
										default:	uint16_tobin)(x, y)

/*
**	Function Prototypes.
*/
uint16_t	create_mask(uint8_t offset);
uint16_t	msk_grp(uint8_t width, uint8_t pos);
uint16_t	test_bit(uint8_t pos, uint16_t val);
uint16_t	set_bit(uint8_t pos, uint16_t val);
uint16_t	clear_bit(uint8_t pos, uint16_t val);
uint16_t	toggle_bit(uint8_t pos, uint16_t val);
uint16_t	read_group(uint8_t pos, uint8_t width, uint16_t val);
uint16_t	write_group(uint8_t pos, uint8_t width, uint16_t val, uint8_t grp);
char		*uint8_tobin(uint8_t n, uint8_t nibblify);
char		*uint16_tobin(uint16_t n, uint8_t nibblify);

#endif