#ifndef DICT_INFO_H
#define DICT_INFO_H
/*** dict_info.h - Defines the universal dict_info_t data structure which each
 *** dictionary can provide, and algorithms can use.  An algorithm which uses
 *** the universal definition of a dictionary data structure can use different
 *** dictionaries interchangeably for testing or comparison purposes.
 ***/

/* Structure that is provided to algorithm which uses a dictionary. */
typedef struct dict_info {
    void *(*alloc)(int (* compar)(const void *, const void *),
            unsigned int (* getval)(const void *));
    void (*free)(void *t);
    void *(*insert)(void *t, void *item);
    void *(*delete_item)(void *t, void *key_item);
    void *(*delete_min)(void *t);
    void *(*find)(void *t, void *key_item);
    void *(*find_min)(void *t);
} dict_info_t;

/* A pointer to a compar() function, which compares two items in the
 * dictionary, is normally supplied as an argument to a dictionaries alloc()
 * function.  However, some dictionaries instead use a getval() function, which
 * evaluates an item in the dictionary to an integer.  To accommodate this, the
 * universal alloc() function in the dict_info structure has two parameters:
 * One for compar() and one for getval().
 *
 * Either the compar() or getval() parameter will be passed as an argument to
 * the actual alloc() function of the dictionary, while the other parameter
 * will be ignored.
 *
 * If an algorithm will only ever use comparison based dictionaries then the a
 * NULL pointer argument can be passed for the getval() parameter when the
 * algorithm calls the universal alloc() function.
 */

#endif
