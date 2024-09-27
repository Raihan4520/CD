#include <stdio.h>
#include <string.h>
#include <memory.h>
#include <stdbool.h>

struct jag{
    char index[20];
};

struct jag eNFA[20][20], NFA[20][20], DFA[20][20], discuss[20];
char result[30][30],copy, copy1, states[20], symbols[20], states2[40], backup[40], cat[40], ch;
bool access = false;
int eNFA_r = 0, eNFA_c = 0, NFA_r = 0, NFA_c = 0, DFA_r = 0, DFA_c = 0, plen = -1, dlen = -1, nlen = -1, s, s1, g;

int size(char *p)
{
    int k = 0;
    int count = 0;
    while (*(p + k) != '\0')
    {
        ++count;
        ++k;
    }
    return count;
}
void input_NFA()
{
    int state, symbol, a;
    NFA[0][0].index[0] = '-';
    printf("**Total number of states: ");
    scanf("%d",&state);
    getchar();
    NFA_r = state;
    printf("**Enter states with a space: ");
    for(int i = 1; i <= NFA_r; i++)
    {
        char x;
        scanf("%c",&x);
        states[i-1] = x;
        NFA[i][0].index[0] = x;
        states[i-1] = x;
        if(i == NFA_r)
            getchar();
        else
            getchar();
    }
    printf("**Total number of symbol: ");
    scanf("%d",&symbol);
    getchar();
    NFA_c = symbol;
    printf("**Enter symbols with a space: ");
    for(int i = 1; i <= NFA_c; i++)
    {
        char x;
        scanf("%c",&x);
        NFA[0][i].index[0] = x;
        DFA[0][i].index[0] = x;
        symbols[i-1] = x;
        if(i == NFA_c)
            getchar();
        else
            getchar();
    }
    for(int i = 1 ; i <= NFA_r; i++)
    {
        for(int j = 1; j <= NFA_c; j++)
        {
            char x = 'P';
            NFA[i][j].index[0] = x;
        }
    }
    for(int i = 1 ; i <= NFA_r; i++)
    {
        for(int l = 1; l <= NFA_c; l++)
        {
            char string[10];
            printf("\n**Transitions of { %c } with symbol { %c }: \nExample: X,Y,Z and PRESS <enter> for no transition.\n>> ", NFA[i][0].index[0], NFA[0][l].index[0]);
            gets(string);

            int s2 = size(&string[0]);
            int ct = 0;

            for(int j = 0; j < s2; j++){
                if(string[j] != ','){
                    FILE *fptr;
                    fptr = fopen("transition.txt", "a");
                    fprintf(fptr, "%c %c %c", NFA[i][0].index[0], NFA[0][l].index[0], string[j]) ;
                    fprintf(fptr, "\n") ;
                    fclose(fptr);
                }
            }
            if(s2 > nlen){
                nlen = s2;
            }

            char * token = strtok(string, " ");
            if((string[0] >= 60 && string[0] <= 90) ||
               (string[0] >= 97 && string[0] <= 122))
            {
                strcpy(NFA[i][l].index, token);
            }
            printf("\n");
        }
   }
}

void input_eNFA()
{
    int state, symbol, a;
    eNFA[0][0].index[0] = '-';
    printf("**Total number of states: ");
    scanf("%d",&state);
    getchar();
    eNFA_r = state;
    printf("**Enter states with a space: ");
    for(int i = 1; i <= eNFA_r; i++)
    {
        char x;
        scanf("%c",&x);
        states[i-1] = x;
        eNFA[i][0].index[0] = x;
        states[i-1] = x;
        if(i == eNFA_r)
            getchar();
        else
            getchar();
    }
    printf("**Total number of symbol: ");
    scanf("%d",&symbol);
    getchar();
    eNFA_c = symbol;
    printf("**Enter symbols with a space: ");
    for(int i = 1; i <= eNFA_c; i++)
    {
        char x;
        scanf("%c",&x);
        eNFA[0][i].index[0] = x;
        symbols[i-1] = x;
        if(i == eNFA_c)
            getchar();
        else
            getchar();
    }
    for(int i = 1 ; i <= eNFA_r; i++)
    {
        for(int j = 1; j <= eNFA_c; j++)
        {
            char x = 'P';
            eNFA[i][j].index[0] = x;
        }
    }
    for(int i = 1 ; i <= eNFA_r; i++)
    {
        for(int l = 1; l <= eNFA_c; l++)
        {
            char string[10];
            printf("\n**Transitions of { %c } with symbol { %c }: \nExample: X,Y,Z and PRESS <enter> for no transition.\n>> ", eNFA[i][0].index[0], eNFA[0][l].index[0]);
            gets(string);

            int s2 = size(&string[0]);
            if(s2 > plen){
                plen = s2;
            }
            for(int j = 0; j < s2; j++){
                if(string[j] != ','){
                    FILE *fptr;
                    fptr = fopen("transition.txt", "a");
                    fprintf(fptr, "%c %c %c", eNFA[i][0].index[0], eNFA[0][l].index[0], string[j]) ;
                    fprintf(fptr, "\n") ;
                    fclose(fptr);
                }
            }
            char * token = strtok(string, " ");
            if((string[0] >= 60 && string[0] <= 90) ||
               (string[0] >= 97 && string[0] <= 122)||
                (string[0] >= '0' && string[0] <= '9'))
            {
                strcpy(eNFA[i][l].index, token);
            }
            printf("\n");
        }
   }

}


void show_eNFA()
{
    printf("\n.....................................\n");
    for(int i =0 ; i <= eNFA_r; i++)
    {
        for(int j = 0; j <= eNFA_c; j++)
        {
            int l = 0;
            while(eNFA[i][j].index[l] != '\0'){
                if(eNFA[i][j].index[l] == 'P')
                {
                    printf("%c", 210);
                }
                else
                {
                    printf("%c",eNFA[i][j].index[l]);
                }
                l++;
            }
            int s2 = size(&eNFA[i][j].index[0]);
            if(s2 > 1)
            {
                for(int k = 0; k < plen - (s2-1) + 1; k++)
                {
                    printf(" ");
                }
            }
            else{
                for(int k = 0; k < plen + 1; k++)
                {
                    printf(" ");
                }
            }
        }
        printf("\n");
    }
}
void show_NFA()
{
    printf("\n     \"\"Inputed NFA\"\"");
    printf("\n.....................................\n");

    for(int i =0 ; i <= NFA_r; i++)
    {
        for(int j = 0; j <= NFA_c; j++)
        {
            int l = 0;
            while(NFA[i][j].index[l] != '\0'){
                if(NFA[i][j].index[l] == 'P')
                {
                    printf("%c", 210);
                }
                else
                {
                    printf("%c", NFA[i][j].index[l]);
                }
                l++;
            }
            int s2 = size(&NFA[i][j].index[0]);
            if(s2 > 1)
            {
                for(int k = 0; k < nlen - (s2-1) + 1; k++)
                {
                    printf(" ");
                }
            }
            else{
                for(int k = 0; k < nlen + 1; k++)
                {
                    printf(" ");
                }
            }
        }
        printf("\n");
    }
}
void show_DFA()
{
    printf("\n   \"\"Displaying Converted DFA\"\"");
    printf("\n.....................................\n");

    DFA[0][0].index[0] = '-';
    for(int i =0 ; i <= DFA_r + 1; i++)
    {
        for(int j = 0; j <= DFA_c + 1; j++)
        {
            int l = 0;
            int fl = 0;
            int s2 = size(&DFA[i][j].index[0]);
            while(DFA[i][j].index[l] != '\0'){
                if(DFA[i][j].index[l] == 'P')
                {
                    printf("%c",210);
                }
                else if(DFA[i][j].index[l] == ',')
                {
                    fl++;
                }
                else
                {
                    printf("%c",DFA[i][j].index[l]);
                }
                l++;
            }
            s2 = s2 - fl;
            if(s2 > 1)
            {
                for(int k = 0; k < (dlen - s2) + 2; k++)
                {
                    printf(" ");
                }
            }
            else{
                for(int k = 0; k < dlen  + 1; k++)
                {
                    printf(" ");
                }
            }
        }
        printf("\n");
    }
}
void apend(char a, int n, int r){
	result[n][r] = a;
}
void apend1(char a, int r){
	states2[r] = a;
}
void apend_dfa(char a, int r)
{
    backup[r] = a;
}


char* removeDuplicates(char arr[], int n)
{
    int j = 0;

    for (int i = 0; i < n; i++){
        for(j = i + 1; j < n;)
        {
            if(arr[i] == arr[j])
            {
                for(int k = j; k < n - 1; ++k)
                    arr[k] = arr[k + 1];

                arr[n - 1] = '\0';
                --n;

            }
            else
                ++j;
        }
    }
    return arr;
}

void display(){
	for(int j = 0; j < s; j++){
        int col = sizeof(result[j]) / sizeof(char);
        printf("\n**Epsilon closure of %c = { ",states[j]);
        for(int i = 0; i < col; i++)
        {
            printf(" %c",result[j][i]);
            if(result[j][i+1] == '\0')
                break;
        }
        printf(" }");
	}
	printf("\n");
}

bool check(char c,int x, int i)
{
    for(int j = 0; j <= i; j++)
    {
        if(result[x][j] == c)
            return true;
    }
    return false;
}

bool check_symbol(char c, int i)
{
    for(int j = 0; j <= i; j++)
    {
        if(states2[j] == c)
            return true;
    }
    return false;
}

bool check_cl(char c, int i)
{
    for(int j = 0; j <= i; j++)
    {
        if(backup[j] == c)
            return true;
    }
    return false;
}

void closure(char state, int n, int i)
{
    FILE *INPUT;
    INPUT=fopen("transition.txt","r");
    int end;
    char state1[3], input[3], state2[3];
    while(1){

        end = fscanf(INPUT,"%s %s %s",state1, input, state2);
        if (end == EOF){
            break;
        }
        else if( state == state1[0]){
            if(input[0] == 'E'){
                if(check(state2[0], n, i) == false)
                {
                    apend(state2[0], n, ++i);
                }
                if(state2[0] == copy)
                {
                    break;
                }
                else
                {
                    closure(state2[0], n, i);
                }
            }
        }
    }
}
void closure1(char state, char ch, int i)
{
    FILE *INPUT;
    INPUT=fopen("transition.txt","r");
    int end;
    char state1[3], input[3], state2[3];

    while(1){

        end = fscanf(INPUT,"%s %s %s",state1, input, state2);
        if (end == EOF){
            break;
        }
        else if( state == state1[0]){
            if( input[0] == ch ) {
                if(check_symbol(state2[0], i) == false)
                {
                    apend1(state2[0], ++i);
                    g = i;
                }
            }

        }
    }
}
void closure2(char state, int i)
{
    FILE *INPUT;
    INPUT=fopen("transition.txt","r");
    int end;
    char state1[3], input[3], state2[3];
    while(1){

        end = fscanf(INPUT,"%s %s %s",state1, input, state2);
        if (end == EOF){
            break;
        }
        else if( state == state1[0]){
            if( input[0] == 'E' ) {
                if(check_cl(state2[0], i) == false)
                {
                    apend_dfa(state2[0], ++i);

                    g = i;
                }
                if(state2[0] == copy1)
                {
                    break;
                }
                else
                {
                    closure2(state2[0], i);
                }
            }
        }
    }
}
bool check_discuss(char *c, int i)
{
    for(int j = 0; j < i; j++)
    {
        if(!strcmp(discuss[j].index, c))
            return true;
    }
    return false;
}

void add_state(char *c, int i)
{
    int i_size = size(&c[0]);
    for(int j = 1; j < s1 ; j++)
    {
        for(int l = 0; l < i_size; l++)
        {
            for(int m = 1; m <= s; m++)
            {
                if(c[l] == NFA[m][0].index[0])
                {
                    for(int m1 = 1; m1 < s1; m1++)
                    {
                        if(NFA[0][m1].index[0] == DFA[0][j].index[0])
                        {
                            int N_size = size(&NFA[m][m1].index[0]);
                            if(N_size > 1){
                                strcat(cat, NFA[m][m1].index);
                                break;
                            }
                            else if(N_size == 1 && NFA[m][m1].index[0] != 'P')
                            {
                                strcat(cat, NFA[m][m1].index);
                                break;

                            }
                            else if(N_size == 1 && NFA[m][m1].index[0] == 'P' && i_size == 1)
                            {
                                cat[0] = 'P';
                                break;

                            }
                        }
                    }
                    break;
                }
            }
        }
        removeDuplicates(cat, size(&cat[0]));
        char * token = strtok(cat, " ");
        strcpy(DFA[i+1][j].index, token);
        int s2 = size(&DFA[i+1][j].index[0]);
        if(s2 > dlen){
            dlen = s2;
        }
        memset(cat, 0, sizeof(cat));
    }
}

bool end(int i)
{
    for(int k = 1;k <= i; k++){
        for(int j = 1; j < s1; j++){
            if(check_discuss(DFA[k][j].index, i) == false)
                return false;
        }
    }
    return true;
}
void NFA_to_DFA()
{
    if(access == false)
    {
        input_NFA();
        show_NFA();
        s = size(&states[0]);
        s1 = size(&symbols[0]) + 1;
    }
    char catty[20];
    char* token;
    int flag = 0;
    DFA[1][0].index[0] = states[0];
    discuss[0].index[0] = states[0];

    int d_size = 1;

    for(int j = 1; j < s1; j++)
    {

        token = strtok(NFA[1][j].index, " ");
        strcpy(DFA[1][j].index, token);
        int s2 = size(&DFA[1][j].index[0]);
        if(s2 > dlen){
            dlen = s2;
        }
    }
    int l = 1;
    while(1)
    {
        for(int j = 1; j < s1; j++)
        {
            token = strtok(DFA[l][j].index, " ");
            strcpy(catty, token);
            if(check_discuss(catty, d_size) == false)
            {
                if(((catty[0] >= 'a' && catty[0] <= 'z') || (catty[0] >= 'A' && catty[0] <= 'Z') || (catty[0] >= '0' && catty[0] <= '9')) && catty[0] != 'P')
                {
                    strcpy(DFA[d_size + 1][0].index, token);
                    strcpy(discuss[d_size].index, token);
                    add_state(catty, d_size);
                    d_size++;
                }
                else if(flag == 0 && catty[0] == 'P')
                {
                    DFA[d_size + 1][0].index[0] = 'P';
                    for(int pi = 1; pi < s1; pi++)
                    {
                        DFA[d_size + 1][pi].index[0] = 'P';
                    }
                    discuss[d_size].index[0] = 'P';
                    flag = 1;
                    d_size++;
                }
            }
            memset(cat, 0, sizeof(catty));
        }
        if(end(d_size) == true){
            DFA_r = d_size;
            DFA_c = s1 - 1;
            break;
        }
        l++;
    }
    if(access == false)
        show_DFA();
}

void eNFA_to_NFA()
{
    input_eNFA();
    printf("\n     \"\"Inputed epsilon-NFA\"\"");
    show_eNFA();
    s = size(&states[0]);
    s1 = size(&symbols[0]);
	for(int k = 1; k <= s; k++){
		NFA[k][0].index[0] = states[k-1];
	}
	for(int k = 1; k <= s1 - 1; k++){
		NFA[0][k].index[0] = symbols[k-1];
		DFA[0][k].index[0] = symbols[k-1];
	}
	for(int k = 0; k < s; k++){
        int i = -1;
        copy = states[k];
        apend(states[k], k, ++i);
        closure(states[k], k, i);
        for(int j = 0; j < s1 - 1; j++)
        {
            int f = 0;
            g = -1;
            while(result[k][f] != '\0')
            {
                closure1(result[k][f], symbols[j], g);
                f++;

            }
            if(g != -1)
            {
                f = 0;
                g = -1;
                int s_state2 = size(&states2[0]);
                while(states2[f] != '\0')
                {
                    copy1 = states2[f];
                    if(check_cl(states2[f], g) == false){
                        apend_dfa(states2[f], ++g);
                    }
                    closure2(states2[f], g);
                    f++;
                }
                char * token = strtok(backup, " ");
                strcpy(NFA[k + 1][j + 1].index, token);
                memset(backup, 0, sizeof(backup));
            }
            else
            {
                NFA[k + 1][j + 1].index[0] = 'P';
            }
        }
        memset(states2, 0, sizeof(states2));
	}
	display();
	printf("\n");

	NFA_to_DFA();
	show_DFA();
}

int main()
{
    FILE *fptr;
    fptr = fopen("transition.txt","w");

    printf("\n\t\t\t\t\t\"\"Converting NFA or Epsilon-NFA to DFA\"\"");
    printf("\n........................................................................");
    printf("................................................");
    printf("\t\t\t\t\t    **[Phi is represent as {P}]**");
    printf("\n\t\t\t\t         **[So avoid using {P} as a state]**");
    printf("\n\t\t\t\t          **[Epsilon is represent as {E}]**");
    printf("\n\t\t\t\t     **[So enter {E} for representing Epsilon]**\n");
    printf("........................................................................");
    printf("................................................");
    printf("\nDoes your NFA have any epsilon Transition? (y/n): ");

    scanf("%c",&ch);
    getchar();

    printf("\n");

    if(ch == 'Y' || ch == 'y')
    {
        access = true;
        eNFA_to_NFA();
    }
    else
    {
        NFA_to_DFA();
    }

    return 0;
}

