/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeimlin <adeimlin@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 12:11:22 by adeimlin          #+#    #+#             */
/*   Updated: 2025/06/16 17:34:35 by adeimlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

// Includes	and Structs ------------------------------------------------------
# include <stdint.h>
# include <unistd.h>
# include "libft_types.h"
//----------------------------------------------------------------------------

# define U32 uint32_t
# define U64 uint64_t

// Prototypes: Core ----------------------------------------------------------
void	*ft_calloc(size_t arr_size, size_t type_size);
void	*ft_realloc(void *src, size_t src_size, size_t dst_size);
void	**ft_free_array(void *array, size_t length);
// Prototypes: Memory --------------------------------------------------------
void	*ft_memset(void *dst_void, const uint8_t byte, size_t length);
int64_t	ft_memcmp(const void *ptr1_void, const void *ptr2_void, size_t length);
int64_t	ft_memrcmp(const void *ptr1_void, const void *ptr2_void, size_t length);
void	*ft_memcpy(void *dst_void, const void *src_void, size_t length);
void	*ft_memchr(const void *ptr_void, uint8_t byte, size_t length);
//----------------------------------------------------------------------------

// Prototypes: Input/Output --------------------------------------------------
ssize_t	ft_putstr(char *str, int fd, uint8_t newline);
ssize_t	ft_putnbr(int64_t number, int fd);
ssize_t	ft_putnchar(const char c, size_t length);
ssize_t	ft_putbits(const uint8_t byte);
int64_t	ft_atoi(const char *num_str);
char	*ft_itoa(int64_t number);
char	*ft_itoa_stack(int64_t number, char *ptr);
U64		ft_atoi_hex(const char *str);
int64_t	ft_atoi_base(const char *str, const char *base);
char	*ft_itoa_base(const int64_t number, const char *base);
char	*get_next_line(int fd);
ssize_t	ft_printf(const char *str, ...);
//----------------------------------------------------------------------------

// Prototypes: Math ----------------------------------------------------------
float	ft_qinvsqrt(float number);
float	ft_qsqrt(float number);
float	ft_average(float *array, uint32_t length);
U32		ft_log2(uint32_t number);
U32		ft_log(uint64_t number, uint8_t base);
int64_t	ft_sqrt(int64_t number);
int64_t	ft_factorial(int64_t number);
int64_t	ft_power(int64_t number, uint64_t power);
size_t	ft_fibonacci(size_t index);
uint8_t	ft_isprime(size_t number);
// Prototypes: Array Info ----------------------------------------------------
size_t	i32_min_index(int32_t *array, size_t length);
size_t	i32_max_index(int32_t *array, size_t length);
size_t	i64_min_index(int64_t *array, size_t length);
size_t	i64_max_index(int64_t *array, size_t length);
// Prototypes: Number Info ---------------------------------------------------
int64_t	i64_min(int64_t number1, int64_t number2);
int64_t	i64_max(int64_t number1, int64_t number2);
int64_t	i64_abs(int64_t number);
int64_t	i64_absdiff(int64_t number1, int64_t number2);
// Prototypes: Linked Lists --------------------------------------------------
//----------------------------------------------------------------------------

// Prototypes: Strings -------------------------------------------------------
size_t	ft_strlen(const char *str);
size_t	ft_replace(char *str, unsigned char old_char, unsigned char new_char);
int32_t	ft_strcmp(const char *str1, const char *str2);
int32_t	ft_strncmp(const char *str1, const char *str2, size_t length);
// Prototypes: String Bools --------------------------------------------------
uint8_t	ft_isalpha(int32_t c);
uint8_t	ft_isdigit(int32_t c);
uint8_t	ft_isspace(int32_t c);
uint8_t	ft_isprint(int32_t c);
uint8_t	ft_isascii(int32_t c);
uint8_t	ft_ischarset(const char c, const char *charset);
// Prototypes: String Copy ---------------------------------------------------
char	*ft_strcpy(char *dst, const char *src);
char	*ft_strncpy(char *dst, const char *src, size_t length);
size_t	ft_strlcpy(char *dst, const char *src, size_t dst_size);
char	*ft_strdup(const char *src);
char	*ft_substr(const char *str, size_t start, size_t length);
// Prototypes: String Find ---------------------------------------------------
char	*ft_strchr(const char *str, unsigned char c);
char	*ft_strrchr(const char *str, unsigned char c);
char	*ft_strfind(const char *str, const char *charset, unsigned char ref);
char	*ft_strstr(const char *str, const char *substr);
char	*ft_strnstr(const char *str, const char *substr, size_t length);
// Prototypes: String Join ---------------------------------------------------
char	*ft_strcat(char *dst, const char *src);
char	*ft_strncat(char *dst, const char *src, size_t length);
size_t	ft_strlcat(char *dst, const char *src, size_t dst_size);
char	*ft_strjoin(const char *src1, const char *src2);
// Prototypes: String Operations ---------------------------------------------
char	**ft_split(const char *str, const char c);
char	**ft_arena_split(const char *str, const char *charset, size_t *count);
char	*ft_strtrim(const char *str, const char *charset);
// Prototypes: String Utils --------------------------------------------------
size_t	ft_count_words(const char *str, const char c);
size_t	ft_count_tokens(const char *str, const char *charset, size_t *bytes);
//----------------------------------------------------------------------------

// Prototypes: Utilities -----------------------------------------------------
t_list	*ft_lstnew(void *content);
t_list	*ft_lstlast(t_list *lst);
size_t	ft_lstsize(t_list *lst);
void	ft_lstadd_front(t_list **lst, t_list *new);
void	ft_lstadd_back(t_list **lst, t_list *new);
// Prototypes: RNG -----------------------------------------------------------
U64		ft_splitmix64(uint64_t seed);
U64		ft_rand(void);
// Prototypes: Sort ----------------------------------------------------------
void	ft_bubble_sort(int32_t *array, size_t length);
void	ft_selection_sort(int32_t *array, size_t length);
void	ft_insertion_sort(int32_t *array, size_t length);
// Prototypes: Swap ----------------------------------------------------------
void	ft_swap(void *a_void, void *b_void, size_t length);
void	ft_swap8(void *a, void *b);
void	ft_swap32(void *a, void *b);
void	ft_swap64(void *a, void *b);
void	ft_reverse(void *array, size_t length, size_t element_size);
//----------------------------------------------------------------------------
#endif
