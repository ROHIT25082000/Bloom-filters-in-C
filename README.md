How to Run 
#include the header bloom_filter.h and use it. 

Compilation with -lm flag .<br>
$ gcc -c test2.c<br>
$ gcc -c bloom_filters.c<br> 
$ gcc test2.o bloom_filters.o -lm<br>
$ ./a.out<br>


## Design of probabilistic data structure for Filtering pattern in C also known as bloom filter  

## Bloom Filtering as Design Pattern is part of Filtering Pattern in General. 

## Pattern Description : 

Bloom filters are simply filters of data which evaluate each data record separately 
and makes the desicion on some property or rule so to make whether the current record 
will pass through the filter or not . Incase of the bloom filters we use a tuple of 
hashing function on each of the records and then decide the result . 

## Intent

Bloom filter tries to answer the question of set membership by the looking for the 
fixed number of hot values (set bits) this fixed number is basically the number of 
hashing function . The job of these is to extract features from a given input record 
and generate hot values . This way it tries to answer the set membership . 
The queries of the bloom filters may become little inaccurate and we call this 
as false positivity . 

## Motivation 

Have you ever found yourself in a situation where you needed to keep track of whether
or not you’ve seen an item but the number of items you have to keep track of is either 
gigantic or completely unbounded . Now if you make a hash map for such a gigantic data 
a lot of memory is going to be used and it would seem impractical Eg . Keeping 
track of large Google Search Engine . Bloom filter comes to your recue and helps 
you do this task with an extremely space efficient method with remarkable accuracy . 

## Working 

We create a probabilistic data structure which is called as bloom filter . 
It consists of a bit vector of length (n) based on the expected number of inputs 
(m) . It first calculates the optimum number of hashing functions (K) to be used per input 
record based on expected false positivity rate (p) of the bloom filter implementation. 

Now on a given input string we calculate K hashes values from K hash function where each would output
a number in the range [0, m) and these set of indices in the bit array would be set up. 
Hashing functions will always generate the same output index tuple for a particular string . 
This way a string is added to the bloom filter . 

To do a look up in the bloom filter for a string is always done by looking at the hashed indices in 
the bit array and if all are not hot in the tuple of indices then we can perfectly say that particular
element has not been seen yet . 
If all bits are up then we can say that element has been seen before with false positivity probability = "p".

## Applicability 

We can use bloom filter where the some false positive result are okay . 

## Consequences 

When a trained bloom filter is exposed to a set of strings then it produces an output which has 
a subset of the input set which passed the membership test . 

But the bloom filter can also output the strings which were not added because of false positivity.  

## Known uses

Sometimes, checking whether some value is a member of a set is going to be expensive. For example, you might have to hit a webservice or an external database to check whether that value is in the set. The situations in which this may be the case are far and few between, but they do crop up in larger organizations. Instead of dumping this list periodically to your cluster, you can instead have the originating system produce a Bloom filter and ship that instead. Once you have the Bloom filter in place and filter out most of the data, you can do a second pass on the records that make it through to double check against the authoritative source. If the Bloom filter is able to remove over 95% of the data, you’ll see the external resource hit only 5% as much as before! With this approach, you’ll eventually have 100% accuracy but didn’t have to hammer the external resource with tons of queries. 

## Resemblances 

Bloom Filter are hot in the fields of big data and Data analytics . Present technology gets benefit from the data being 
big is exploitable in Pig and SQL as they can use bloom filter . 

## Performances . 

The performances of the bloom filter are very great as they are faster and extremely space efficient and can be 
implemented in a file too ! . The hash functions also more or less cheap time. 
The look up operation is also very cheap in bloom filters O(1) time. 


In My implementation we have the following functions 

# Initialize a bloom filter with approximate number of elements , false positivity and your desired hashing function . 
int bloom_filter_init(bloom_filter * bloomFilter, uint64_t approximate_elements, float false_positivity, bloom_hash hash_func); 

# Displays the health of the bloom filter . 
void stats_bloom_filter(bloom_filter * bloomFilter); 

# Destroy the bloom filter and free up memory 
int free_bloom_filter(bloom_filter * bloomFilter);  

# Make the bloom filter fresh again after health detoriates 
int reset_bloom_filter(bloom_filter * bloomFilter); 

# Add a string in the bloom filter . 
int add_string(bloom_filter * bloomFilter, const char * string); 

# Look up in the bloom filter . 
int is_present_bloom_filter(bloom_filter * bloomFilter, const char * str);  

# Look at the current false positivity of the bloom filter . 
float get_current_positivity_rate(bloom_filter * bloomFilter);  

# Gets the number of hot bits 
uint64_t count_bits_set(bloom_filter * bloomFilter);

# Estimates the number of elements added. 
uint64_t estimating_elements(bloom_filter * bloomFilter);


# operations on bloom filters 

# find union of two bloom filters with same n and hash function
bloom_filter * union_bloom_filters(bloom_filter * source1, bloom_filter * source2);  

# find intersection of two bloom filters with same hash function  
bloom_filter * intersection_bloom_filters(bloom_filter * source1, bloom_filter * source2); 

# Index which calculates how similar are two bloom filters .
long double jaccard_index_bloom_filters(bloom_filter * source1, bloom_filter * source2); 

