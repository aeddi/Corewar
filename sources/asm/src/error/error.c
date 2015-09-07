/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_cmd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gponsine <gponsine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/24 00:56:35 by gponsine          #+#    #+#             */
/*   Updated: 2014/01/29 14:24:57 by gponsine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm_parse.h"
#include "asm_error.h"

static void	error_cmd_type(t_parse *p)
{
	ft_putstr_fd("asm: Invalid cmd type, line : ", 2);
	ft_putnbr_fd(LINE_NBR, 2);
	ft_putstr_fd(", char : ", 2);
	ft_putnbr_fd(POS, 2);
	ft_putchar_fd('\n', 2);
}

static void	error_char(t_parse *p)
{
	if (LINE(POS))
	{
		ft_putstr_fd("asm: Invalid character '", 2);
		ft_putchar_fd(LINE(POS), 2);
		ft_putstr_fd("', line : ", 2);
	}
	else
		ft_putstr_fd("asm: Invalid end of line, line : ", 2);
	ft_putnbr_fd(LINE_NBR, 2);
	ft_putstr_fd(", char : ", 2);
	ft_putnbr_fd(POS, 2);
	ft_putchar_fd('\n', 2);
}

static void	error_cmd_string_length(t_parse *p)
{
	ft_putstr_fd("asm: cmd string too long line : '", 2);
	ft_putchar_fd(LINE(POS), 2);
	ft_putstr_fd("', line : ", 2);
	ft_putnbr_fd(LINE_NBR, 2);
	ft_putstr_fd(", char : ", 2);
	ft_putnbr_fd(POS, 2);
	ft_putchar_fd('\n', 2);
}

static void	error_mnemonic(t_parse *p)
{
	ft_putstr_fd("asm: Invalid mnemonic \"", 2);
	ft_putstr_fd(LEXEM, 2);
	ft_putstr_fd("\", line : ", 2);
	ft_putnbr_fd(LINE_NBR, 2);
	ft_putstr_fd(", char : ", 2);
	ft_putnbr_fd(POS, 2);
	ft_putchar_fd('\n', 2);
}

static void	error_instruct_arg(t_parse *p)
{
	ft_putstr_fd("asm: Invalid argument \"", 2);
	ft_putstr_fd(LEXEM, 2);
	ft_putstr_fd("\", line : ", 2);
	ft_putnbr_fd(LINE_NBR, 2);
	ft_putstr_fd(", char : ", 2);
	ft_putnbr_fd(POS, 2);
	ft_putchar_fd('\n', 2);
}

static void	error_label_name(t_parse *p)
{
	ft_putstr_fd("asm: Invalid label name \"", 2);
	ft_putstr_fd(LEXEM, 2);
	ft_putstr_fd("\", line : ", 2);
	ft_putnbr_fd(LINE_NBR, 2);
	ft_putstr_fd(", char : ", 2);
	ft_putnbr_fd(POS, 2);
	ft_putchar_fd('\n', 2);
}

static void error_label_exist(char *p)
{
	ft_putstr_fd("asm: Label \"", 2);
	ft_putstr_fd(p, 2);
	ft_putstr_fd("\" does not exist\n", 2);
}

int		error(enum e_error e, void *p)
{
	if (e == CMD)
		error_cmd_type(p);
	if (e == CMD_STRING_LENGTH)
		error_cmd_string_length(p);
	if (e == INVALID_CHAR)
		error_char(p);
	if (e == MNEMONIC)
		error_mnemonic(p);
	if (e == ARG)
		error_instruct_arg(p);
	if (e == LABEL_NAMED)
		error_label_name(p);
	if (e == LABEL_EXIST)
		error_label_exist(p);
	exit(0);
	return (1);
}
