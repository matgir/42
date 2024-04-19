#include <stdio.h>

struct	int_list_s		{int n;			struct int_list_s * next;};
struct	float_list_s	{float z;		struct float_list_s * next;};
struct	string_list_s	{char * str;	struct string_list_s * next;};

typedef struct	int_list_s		int_list_t;
typedef struct	float_list_s	float_list_t;
typedef struct	string_list_s	string_list_t;

int_list_t *	int_list_new(int n);
float_list_t *	float_list_new(float z);
string_list_t *	string_list_new(char const * str);

void	int_list_delete(int_list_t ** list);
void	float_list_delete(float_list_t ** list);
void	string_list_delete(string_list_t ** list);

/* Etc... */

struct	list_s
{
	void *			content;
	size_t			size;
	struct list_s *	next;
};

typedef struct	list_s	list_t;

list_t *	list_new(void * content, size_t size);
void		list_delete(list_t ** list);

/* Etc... */

int	main(void)
{
	/* Etc... */

	return 0;
}