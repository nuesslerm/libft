/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnussler <mnussler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 00:43:31 by mnussler          #+#    #+#             */
/*   Updated: 2025/05/13 16:11:46 by mnussler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stddef.h>

/* Part 1 - Libc Functions */

/**
 * @brief Checks for an alphabetic character.
 * @param c The character to check.
 * @return 1 if `c` is a letter, 0 otherwise.
 */
int					ft_isalpha(int c);

/**
 * @brief Checks for a digit (0 through 9).
 * @param c The character to check.
 * @return 1 if `c` is a digit, 0 otherwise.
 */
int					ft_isdigit(int c);

/**
 * @brief Checks for an alphanumeric character.
 * @param c The character to check.
 * @return 1 if `c` is a letter or digit, 0 otherwise.
 */
int					ft_isalnum(int c);

/**
 * @brief Checks if `c` fits into the ASCII character set.
 * @param c The character to check.
 * @return 1 if `c` is an ASCII character, 0 otherwise.
 */
int					ft_isascii(int c);

/**
 * @brief Checks for any printable character including space.
 * @param c The character to check.
 * @return 1 if `c` is printable, 0 otherwise.
 */
int					ft_isprint(int c);

/**
 * @brief Calculates the length of the string `s`.
 * @param s The string to measure.
 * @return The number of bytes in the string `s`.
 */
size_t				ft_strlen(const char *s);

/**
 * @brief Fills the first n bytes of the memory area `b` with the constant
 * byte `c`.
 * @param b Pointer to the memory area.
 * @param c The byte value to fill with (converted to unsigned char).
 * @param n The number of bytes to fill.
 * @return A pointer to the memory area `b`.
 */
void				*ft_memset(void *b, int c, size_t n);

/**
 * @brief Writes `n` zeroed bytes to the string `s`.
 * @param s Pointer to the memory area.
 * @param n The number of bytes to zero.
 */
void				ft_bzero(void *s, size_t n);

/**
 * @brief Copies `n` bytes from `src` to `dst`. Memory areas must not overlap.
 * @param dst Destination memory area.
 * @param src Source memory area.
 * @param n Number of bytes to copy.
 * @return A pointer to `dst`.
 */
void				*ft_memcpy(void *dst, const void *src, size_t n);

/**
 * @brief Copies `len` bytes from `src` to `dst`. Memory areas may overlap.
 * Copies the bytes in a non-destructive manner.
 * @param dst Destination memory area.
 * @param src Source memory area.
 * @param len Number of bytes to copy.
 * @return A pointer to `dst`.
 */
void				*ft_memmove(void *dst, const void *src, size_t len);

/**
 * @brief Copies up to `dstsize - 1` chars from `src` to `dst`,
 * `NULL`-terminating.
 * @param dst Destination buffer.
 * @param src Source string.
 * @param dstsize Size of the destination buffer.
 * @return The total length of the string it tried to create (`strlen(src)`).
 */
size_t				ft_strlcpy(char *dst, const char *src, size_t dstsize);

/**
 * @brief Appends `src` to `dst`, `NULL`-terminating.
 * Appends at most `dstsize - strlen(dst) - 1` bytes.
 * @param dst Destination buffer.
 * @param src Source string.
 * @param dstsize Size of the destination buffer.
 * @return The total length of the string it tried to create
 * (`strlen(dst) + strlen(src)`).
 */
size_t				ft_strlcat(char *dst, const char *src, size_t dstsize);

/**
 * @brief Converts a lower-case letter to the corresponding upper-case letter.
 * @param c The ASCII value of the character to convert
 * @return The converted letter, or `c` if the conversion was not possible.
 */
int					ft_toupper(int c);

/**
 * @brief Converts an upper-case letter to the corresponding lower-case letter.
 * @param c The ASCII value of the character to convert
 * @return The converted letter, or `c` if the conversion was not possible.
 */
int					ft_tolower(int c);

/**
 * @brief Locates the first occurrence of `c` in the string `s`.
 * @param s The string to search.
 * @param c The ASCII value of the character to find
 * @return A pointer to the located char, or `NULL` if not found.
 */
char				*ft_strchr(const char *s, int c);

/**
 * @brief Locates the last occurrence of `c` in the string `s`.
 * @param s The string to search.
 * @param c The ASCII value of the character to find
 * @return A pointer to the located char, or `NULL` if not found.
 */
char				*ft_strrchr(const char *s, int c);

/**
 * @brief Compares the first `n` bytes of strings `s1` and `s2`.
 * @param s1 The first string.
 * @param s2 The second string.
 * @param n The maximum number of bytes to compare.
 * @return An integer <, ==, or > to 0, if `s1` <, ==, or > `s2`.
 */
int					ft_strncmp(const char *s1, const char *s2, size_t n);

/**
 * @brief Scans the first `n` bytes of memory area `s` for the first
 * instance of `c`.
 * @param s The memory area to scan.
 * @param c The byte to find (converted to unsigned char).
 * @param n The number of bytes to scan.
 * @return A pointer to the matching byte or `NULL` if not found.
 */
void				*ft_memchr(const void *s, int c, size_t n);

/**
 * @brief Compares the first `n` bytes of memory areas `s1` and `s2`.
 * @param s1 The first memory area.
 * @param s2 The second memory area.
 * @param n The number of bytes to compare.
 * @return An integer <, ==, or > to 0, if `s1` <, ==, or > `s2`.
 */
int					ft_memcmp(const void *s1, const void *s2, size_t n);

/**
 * @brief Locates the first occurrence of `needle` in `haystack`,
 * searching at most `len` chars.
 * @param haystack The string to search in.
 * @param needle The string to search for.
 * @param len The maximum number of characters to search.
 * @return A pointer to the beginning of the located substring,
 * or `NULL` if not found.
 */
char				*ft_strnstr(const char *haystack, const char *needle,
						size_t len);

/**
 * @brief Converts the initial portion of the string `str` to an integer.
 * @param str The string to convert.
 * @return The converted integer value.
 */
int					ft_atoi(const char *str);

/**
 * @brief Allocates contiguous memory for an array of `count` elements of
 * `size` bytes each, initialized to zero.
 * @param count The number of elements.
 * @param size The size of each element (in bytes).
 * @return A pointer to the allocated memory, or `NULL` if allocation fails.
 */
void				*ft_calloc(size_t count, size_t size);

/**
 * @brief Returns a malloc'd duplicate of the string `s1`.
 * @param s1 The string to duplicate.
 * @return A pointer to the duplicated string, or `NULL` if allocation fails.
 */
char				*ft_strdup(const char *s1);

/* Part 2 - Additional Functions */

/**
 * @brief Allocates and returns a substring from string `s` starting at `start`
 * with max length `len`.
 * @param s The original string.
 * @param start The starting index of the substring.
 * @param len The maximum length of the substring.
 * @return The substring, or `NULL` if allocation fails.
 */
char				*ft_substr(char const *s, unsigned int start, size_t len);

/**
 * @brief Allocates and returns a new string, result of concatenating
 * `s1` and `s2`.
 * @param s1 The first string.
 * @param s2 The second string.
 * @return The new string, or `NULL` if allocation fails.
 */
char				*ft_strjoin(char const *s1, char const *s2);

/**
 * @brief Allocates and returns a copy of `s1` with characters from `set`
 * removed from the beginning and end.
 * @param s1 The string to trim.
 * @param set The set of characters to remove.
 * @return The trimmed string, or `NULL` if allocation fails.
 */
char				*ft_strtrim(char const *s1, char const *set);

/**
 * @brief Allocates and returns an array of strings by splitting `s` using
 * delimiter `c`. Array is NULL-terminated.
 * @param s The string to split.
 * @param c The delimiter character.
 * @return The array of new strings, or `NULL` if allocation fails.
 */
char				**ft_split(char const *s, char c);

/**
 * @brief Allocates and returns a string representing the integer `n`.
 * @param n The integer to convert.
 * @return The string representation of the integer, or `NULL`
 * if allocation fails.
 */
char				*ft_itoa(int n);

/**
 * @brief Applies function `f` to each character of `s` to create a new string.
 * @param s The original string.
 * @param f The function to apply to each character (takes index and char).
 * @return The new string created by applying `f`, or `NULL`
 * if allocation fails.
 */
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));

/**
 * @brief Applies function `f` to each character of string `s`(modified in
 * place).
 * @param s The string to iterate over.
 * @param f The function to apply to each character (takes index and pointer to
 * char).
 */
void				ft_striteri(char *s, void (*f)(unsigned int, char *));

/**
 * @brief Outputs the character `c` to the file descriptor `fd`.
 * @param c The character to output.
 * @param fd The file descriptor.
 */
void				ft_putchar_fd(char c, int fd);

/**
 * @brief Outputs the string `s` to the file descriptor `fd`.
 * @param s The string to output.
 * @param fd The file descriptor.
 */
void				ft_putstr_fd(char *s, int fd);

/**
 * @brief Outputs the string `s` to `fd`, followed by a newline.
 * @param s The string to output.
 * @param fd The file descriptor.
 */
void				ft_putendl_fd(char *s, int fd);

/**
 * @brief Outputs the integer `n` to the file descriptor `fd`.
 * @param n The integer to output.
 * @param fd The file descriptor.
 */
void				ft_putnbr_fd(int n, int fd);

/* Bonus Part - Linked List Functions */

/**
 * @brief Structure for a singly linked list node.
 * @param content Pointer to the content of the node.
 * @param next Pointer to the next node in the list.
 */
typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

/**
 * @brief Allocates and returns a new list element with content initialized to
 * `content`.
 * @param content The content for the new node.
 * @return The new node, or `NULL` if allocation fails.
 */
t_list				*ft_lstnew(void *content);

/**
 * @brief Adds the element `new` at the beginning of the list `lst`.
 * @param lst A pointer to the pointer of the first element of the list.
 * @param new The element to add to the list.
 */
void				ft_lstadd_front(t_list **lst, t_list *new);

/**
 * @brief Counts the number of elements in a list.
 * @param lst The beginning of the list.
 * @return The number of elements in the list.
 */
int					ft_lstsize(t_list *lst);

/**
 * @brief Returns the last element of the list.
 * @param lst The beginning of the list.
 * @return The last element of the list, or `NULL` if the list is empty.
 */
t_list				*ft_lstlast(t_list *lst);

/**
 * @brief Adds the element `new` at the end of the list `lst`.
 * @param lst A pointer to the pointer of the first element of the list.
 * @param new The element to add to the list.
 */
void				ft_lstadd_back(t_list **lst, t_list *new);

/**
 * @brief Frees the memory of the element's content using `del` and frees the
 * element.
 * @param lst The element to free.
 * @param del The function used to delete the content.
 */
void				ft_lstdelone(t_list *lst, void (*del)(void *));

/**
 * @brief Deletes and frees the given element and all successors using `del`.
 * Sets list pointer to `NULL`.
 * @param lst A pointer to the pointer of the first element of the list.
 * @param del The function used to delete the content of each element.
 */
void				ft_lstclear(t_list **lst, void (*del)(void *));

/**
 * @brief Iterates the list `lst` and applies function `f` to the content of
 * each element.
 * @param lst The beginning of the list.
 * @param f The function to apply to each element's content.
 */
void				ft_lstiter(t_list *lst, void (*f)(void *));

/**
 * @brief Iterates list `lst`, applies `f` to each element's content,
 * creating a new list. Uses `del` on error.
 * @param lst The beginning of the list.
 * @param f The function to apply to the content of each element.
 * @param del The function used to delete the content of an element if needed.
 * @return The new list, or `NULL` if allocation fails.
 */
t_list				*ft_lstmap(t_list *lst, void *(*f)(void *),
						void (*del)(void *));

#endif
