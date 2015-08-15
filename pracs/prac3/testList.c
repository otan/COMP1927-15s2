#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "list.h"

List createWordList(char *word) {
    int i;
    List l = createList();
    Node curr = NULL;
    for (i = 0; word[i] != 0; i++) {
        Node n = createNode(word[i]);
        n->prev = curr;
        if (curr == NULL) {
            l->first = n;
        } else {
            curr->next = n;
        }
        curr = n;
    }
    l->last = curr;
    return l;
}

int main(int argc, char *argv[]) {
    printf("* Testing part one...\n");
    assert(isPalindrome(createWordList("")));
    assert(isPalindrome(createWordList("m")));
    assert(isPalindrome(createWordList("aa")));
    assert(isPalindrome(createWordList("aaa")));
    assert(isPalindrome(createWordList("baab")));
    assert(isPalindrome(createWordList("bacab")));
    assert(isPalindrome(createWordList("madamadam")));
    assert(isPalindrome(createWordList("!lol!")));
    
    assert(!isPalindrome(createWordList("aaab")));
    assert(!isPalindrome(createWordList("aaabaa")));
    assert(!isPalindrome(createWordList("madam im not adam")));
    assert(!isPalindrome(createWordList("navy league wobs")));
    assert(!isPalindrome(createWordList("shrek was here")));
    assert(!isPalindrome(createWordList("!lol!a")));
    assert(!isPalindrome(createWordList("this is an NP complete problem!")));
    assert(!isPalindrome(createWordList("taylor swift is hot")));
    assert(!isPalindrome(createWordList("7am waking up in the morning")));
    assert(!isPalindrome(createWordList("caesar's catfish")));
    assert(!isPalindrome(createWordList("jimminy jillickers, radioactive man")));
    assert(!isPalindrome(createWordList("gotta catch 'em all, pokemon")));
    assert(!isPalindrome(createWordList("feministas")));
    assert(!isPalindrome(createWordList("It's Pierre's Birthday!")));
    assert(!isPalindrome(createWordList("lemonparty.org")));
    assert(!isPalindrome(createWordList("Okay, I think 139484 tests is enough...")));

    printf("* Part one passed! Not enough for asian father...\n");

    printf("* Testing part two...\n");
    assert(isPalindrome(createWordList("\t\n\t\t")));
    assert(isPalindrome(createWordList("23435436362")));
    assert(isPalindrome(createWordList(",lol!")));
    assert(isPalindrome(createWordList(",lol lol")));
    assert(isPalindrome(createWordList("madam i'm adam")));
    assert(isPalindrome(createWordList("pooP")));
    assert(isPalindrome(createWordList("cAtStac")));
    assert(isPalindrome(createWordList("cAtStac\n")));
    assert(isPalindrome(createWordList("aAAAaAaaAaAAAaaAaA")));
    assert(isPalindrome(createWordList("aAAAaAaa*(#%(&*%(*&$@*&%$@(*&%(*&AaAAAaaAaA")));
    assert(isPalindrome(createWordList("azAAaAaa*(#%(&*%(*&$@*&%$@(*&%(*&AaAAAaaAzA")));
    assert(isPalindrome(createWordList("Eve, mad Adam, Eve!")));
    assert(isPalindrome(createWordList("Resume so pacific a pose, muser.")));
    assert(isPalindrome(createWordList("Marge let a moody baby doom a telegram.")));
    assert(isPalindrome(createWordList("Tenet C is a basis, a basic tenet.")));
    assert(isPalindrome(createWordList("Nella's simple hymn: \"I attain my help, Miss Allen.\"")));
    assert(isPalindrome(createWordList("Straw? No, too stupid a fad. I put soot on warts.")));
    assert(isPalindrome(createWordList("Sir, I demand, I am a maid named Iris.")));
    assert(isPalindrome(createWordList("Lay a wallaby baby ball away, Al.")));

    printf("* All tests passed! Asian father approves.\n");
    return EXIT_SUCCESS;
}
