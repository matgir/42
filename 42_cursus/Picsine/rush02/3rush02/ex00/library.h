/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   library.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llepiney <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/22 10:39:35 by llepiney          #+#    #+#             */
/*   Updated: 2021/08/22 21:56:23 by mgirardo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef LIBRARY_H
# define LIBRARY_H

char			*ten_ten(char num1, char num2);
char			*ten_power(int n);
char			*solo_char(char c);
void			ft_putchar(char c);
void			aff_start(char *txt, char **tab, int n);
void			ft_parsing(char *txt, char *key);
void			aff_pack1(char *txt, char **tab, int n, int pow);
void			aff_pack2(char *txt, char **tab, int n, int pow);
int				ft_chek_arg(char *str);
unsigned int	ft_clean_before_nd_nb_paquets(char *str);
char			*ft_strcpy(char *str);
char			**split(char *str);
int				triple_zero(char **tab, int n);
void			ft_annexe1(char *txt, char **tab, int n);
void			ft_annexe2(char *txt, char **tab, int n);
void			free_tab(char **tab);
void			free_all(char *strcpy, char *solo, char *power, char *tempstr);
int             ft_check_error1(int argc);
int             ft_check_error2(char *str);
char            *ft_define_txt(int argc, char **argv);
char            *ft_define_str(int argc, char **argv);
void            ft_lcmparsing(char **tab, char *txt, char *str);

#endif
