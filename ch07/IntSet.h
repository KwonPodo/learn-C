#ifndef ___IntSet
#define ___IntSet

typedef struct {
    int max; // 집합 최대 개수
    int num;  // 집합 원소 개수
    int *set; // 집합
} intSet;

// Initiate Set
int Init(intSet *s, int max);

// Check if n is in Set s
int IsMember(const intSet *s, int n);

// Check if Set s is Full
int isFull(const intSet *s);

// Check if Set s is Empty
int isEmpty(const intSet *s);

// Add int n to Set s
void Add(intSet *s, int n);

// Remove int n from s
void Remove(intSet *s, int n);

// Clear all elements in Set
void Clear(intSet *s);

// return max num of Set 
int Capacity(const intSet *s);

// return number of elements in Set
int CurrentSize(const intSet *s);

// Copy
// assign Set s2 to s1
void Assign(intSet *s1, const intSet *s2);

// Check if Set s1 and Set s2 is same
int isEqual(const intSet *s1, const intSet *s2);

// Assign Union of Set s2, s3 to Set s1
intSet* Union (intSet *s1, const intSet *s2, const intSet *s3);

// Assign Intersection of Set s2, s3 to Set s1
intSet* Intersection (intSet *s1, const intSet *s2, const intSet *s3);

// Assign Difference s2 - s3 to Set s1
intSet* Difference (intSet *s1, const intSet *s2, const intSet *s3);

// Symmetric Difference between Set s2, Set s3
intSet* SymmetricDiff(intSet *s1, const intSet *s2, const intSet *s3);

// Union Set s2 to Set s1
intSet* ToUnion(intSet *s1, const intSet *s2);

// Delete elements that are not Intersection of Set s1 and Set s2 from Set s1
intSet* ToIntersect(intSet *s1, const intSet *s2);

// Delete intersecting elements between two sets from Set s1
intSet* ToDiff(intSet *s1, const intSet *s2);

// Return 1 if Set s1 is subset of Set s2
int IsSubset(const intSet *s1, const intSet *s2);

// Return 1 if Set s1 is proper subset of Set s2
int IsProperSubset(const intSet *s1, const intSet *s2);

// Print All elements of the given Set
void Print(const intSet *s);

// Print with \n
void PrintLn(const intSet *s);

// Terminate Set
void Terminate(intSet *s);

#endif