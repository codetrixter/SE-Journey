# Chapter 2: Data Models and Query Languages

## Introduction
- Data models are the most important part of developing software.
- They affect how we think about the problem we're solving.
- Applications are built by layering data models:
  1. Application layer: Objects, data structures, APIs.
  2. Storage layer: JSON, XML, tables, graphs.
  3. Database layer: Bytes in memory, disk, network.
  4. Hardware layer: Electrical currents, magnetic fields.

## Relational Model vs. Document Model

### Relational Model
- Proposed by Edgar Codd in 1970.
- Data organized into **relations** (tables), each relation is a collection of **tuples** (rows).
- Dominated for 25-30 years: Business data processing, transaction processing, batch processing.
- Examples: Oracle, MySQL, PostgreSQL, SQL Server.

### The Birth of NoSQL
- NoSQL emerged in 2010s due to:
  - Need for greater scalability (large datasets, high write throughput).
  - Preference for free/open-source software.
  - Specialized query operations not supported by relational model.
  - Frustration with restrictiveness of relational schemas.
  - Desire for more dynamic and expressive data models.
- NoSQL = "Not Only SQL" (polyglot persistence).
- Not a replacement for relational — use the right tool for each job.

#### Categories of NoSQL Databases
| Type | Examples | Use Case |
|------|----------|----------|
| Document | MongoDB, CouchDB, RethinkDB | Content management, catalogs, user profiles |
| Key-Value | Redis, DynamoDB, Riak | Caching, session storage, simple lookups |
| Wide-Column | Cassandra, HBase, Bigtable | Time-series, IoT, write-heavy workloads |
| Graph | Neo4j, Amazon Neptune, Dgraph | Social networks, recommendations, fraud detection |

### The Object-Relational Mismatch
- Most applications use object-oriented programming.
- **Impedance mismatch**: Awkward translation between objects and relational tables.
  - Objects have nested structures, references, inheritance.
  - Tables are flat with rows and columns.
  - Translation layer required in application code.
- ORMs (e.g., Hibernate, ActiveRecord) reduce boilerplate but don't hide the mismatch.
  - Still need to think about how objects map to tables.
  - Complex queries often bypass ORM and use raw SQL.
  - N+1 query problem common with naive ORM usage.

#### Example: LinkedIn Profile
- A résumé has one-to-many relationships:
  - One person → many jobs, education entries, contact info.
- **Relational approach**: Separate tables for positions, education, contact_info with foreign keys.
- **Document approach**: Store entire profile as single JSON document.

```json
{
  "user_id": 251,
  "first_name": "Bill",
  "last_name": "Gates",
  "positions": [
    {"job_title": "Co-chair", "organization": "Bill & Melinda Gates Foundation"},
    {"job_title": "Co-founder, Chairman", "organization": "Microsoft"}
  ],
  "education": [
    {"school_name": "Harvard University", "start": 1973, "end": 1975}
  ],
  "contact_info": {
    "twitter": "BillGates",
    "blog": "https://www.gatesnotes.com"
  }
}
```

### Many-to-One and Many-to-Many Relationships

#### Many-to-One
- Use IDs instead of plain text for normalization.
- Example: Instead of storing "Greater Seattle Area" as text, use `region_id: 123`.
- Benefits:
  - Consistent style and spelling.
  - Easy updates (change in one place).
  - Localization support.
  - Better search.

#### Many-to-Many
- Example: Organizations and schools as entities (not just strings).
  - A user worked at Microsoft → link to Microsoft entity.
  - Microsoft has its own page with logo, news feed, etc.
- Recommendations: "People who worked at Microsoft also worked at..."
- Requires **joins** which are harder in document databases.

### Relational vs. Document Databases Today

| Aspect | Document Model | Relational Model |
|--------|----------------|------------------|
| Schema | Flexible (schema-on-read) | Rigid (schema-on-write) |
| Joins | Weak support | Strong support |
| One-to-many | Natural fit (nested) | Requires joins |
| Many-to-many | Difficult | Natural fit |
| Data locality | Good (single document) | Scattered across tables |

#### When to Use Document Model
- Data has document-like structure (tree of one-to-many).
- Entire document loaded at once.
- Schema flexibility needed.
- Example: Content management systems, event logging.

#### When to Use Relational Model
- Many-to-many relationships common.
- Complex queries and joins needed.
- Strong consistency and transaction support.
- Example: Banking, inventory systems.

### Schema Flexibility
- **Schema-on-read** (document): Structure interpreted when data is read (like dynamic typing).
  - No schema enforced at write time.
  - Application code must handle missing/extra fields.
  - Good for heterogeneous data (each record may have different fields).
  - Migration is gradual: new code handles both old and new formats.
- **Schema-on-write** (relational): Schema enforced when data is written (like static typing).
  - Database rejects data that doesn't match schema.
  - Guarantees data consistency.
  - Schema changes require migrations (ALTER TABLE).
  - Better for homogeneous data with predictable structure.

#### Schema Migration Trade-offs
| Aspect | Schema-on-Read | Schema-on-Write |
|--------|----------------|-----------------|
| Write flexibility | High | Low |
| Read complexity | High (must handle variants) | Low (guaranteed structure) |
| Data quality | Application enforced | Database enforced |
| Migration speed | Instant (no ALTER) | Can be slow for large tables |
| Debugging | Harder (runtime errors) | Easier (compile-time checks) |

#### Example: Splitting Full Name
- Document DB:
  ```javascript
  if (user && user.name && !user.first_name) {
    user.first_name = user.name.split(" ")[0];
  }
  ```
- Relational DB:
  ```sql
  ALTER TABLE users ADD COLUMN first_name TEXT;
  UPDATE users SET first_name = split_part(name, ' ', 1);
  ```

### Data Locality for Queries
- Document model: Entire document stored contiguously → fast to retrieve.
  - Single disk seek to load entire document.
  - Great when you need the whole document (e.g., render a webpage).
- Relational model: Data scattered across tables → multiple index lookups.
  - Need joins to reassemble related data.
  - More flexible for partial reads.
- Trade-off: Updating part of a document may require rewriting the entire document.
  - Only efficient if documents are small and updates are infrequent.
  - Avoid documents that grow unboundedly (e.g., list of all comments).
- **Recommendation**: Keep documents small; avoid writes that increase document size.

#### Locality in Other Databases
- Related concepts providing locality benefits:
  - **Google Spanner**: Interleaved tables (parent-child rows stored together).
  - **Oracle**: Multi-table index clusters.
  - **Cassandra/HBase**: Column families (columns grouped for locality).
  - **Bigtable model**: Related data in same column family read together.

### Convergence of Models
- Relational DBs adding JSON support (PostgreSQL, MySQL, IBM DB2).
- Document DBs adding join support (RethinkDB, MongoDB).
- Hybrid approaches becoming common.

---

## Query Languages for Data

### Declarative vs. Imperative

#### Imperative
- Specify **how** to get the result step by step.
- Example (JavaScript):
  ```javascript
  function getSharks() {
    var sharks = [];
    for (var i = 0; i < animals.length; i++) {
      if (animals[i].family === "Sharks") {
        sharks.push(animals[i]);
      }
    }
    return sharks;
  }
  ```

#### Declarative (SQL)
- Specify **what** result you want, not how to get it.
- Example:
  ```sql
  SELECT * FROM animals WHERE family = 'Sharks';
  ```
- Benefits:
  - Concise and easier to work with.
  - Hides implementation details.
  - Database can optimize execution (query optimizer).
  - Easier to parallelize.
- The query optimizer decides:
  - Which indexes to use.
  - Which order to execute joins.
  - Which algorithm to use for each operation.
- Same query, same result — even if database internals change.
- This is why SQL has survived 40+ years: implementation can improve without breaking queries.

### Declarative Queries on the Web (CSS Example)
- Imperative (JavaScript DOM manipulation):
  ```javascript
  var liElements = document.getElementsByTagName("li");
  for (var i = 0; i < liElements.length; i++) {
    if (liElements[i].className === "selected") {
      var children = liElements[i].childNodes;
      for (var j = 0; j < children.length; j++) {
        if (children[j].nodeType === Node.ELEMENT_NODE && children[j].tagName === "P") {
          children[j].setAttribute("style", "background-color: blue");
        }
      }
    }
  }
  ```
- Declarative (CSS):
  ```css
  li.selected > p {
    background-color: blue;
  }
  ```

### MapReduce Querying
- Programming model for processing large datasets across many machines (popularized by Google in 2004).
- Neither fully declarative nor fully imperative — a hybrid approach.
- Uses two core functions from functional programming:
  - **`map`** (also called collect): Called once for every document, extracts key-value pairs.
  - **`reduce`** (also called fold/inject): Takes all values with the same key and combines them.

#### How MapReduce Works
1. **Map Phase**: The map function is applied to each input record independently.
   - Input: A single document/record.
   - Output: Zero or more key-value pairs via `emit(key, value)`.
   - Can run in parallel across many machines (no coordination needed).

2. **Shuffle Phase**: Framework groups all emitted values by key.
   - All values for the same key are collected together.
   - Data may be transferred across machines.

3. **Reduce Phase**: The reduce function is called once per unique key.
   - Input: A key and an array of all values for that key.
   - Output: A single aggregated result.
   - Can also run in parallel (one reducer per key or key range).

#### Key Characteristics
- **Pure functions**: Map and reduce must be pure (no side effects, same input → same output).
- **Idempotent**: Can be retried on failure without affecting results.
- **Parallelizable**: Framework can distribute work across cluster automatically.
- **Batch-oriented**: Designed for processing entire datasets, not real-time queries.

#### Limitations of MapReduce
- Must be written as two carefully coordinated functions.
- Multiple MapReduce jobs often needed for complex queries (chained jobs).
- Intermediate state written to disk → slower than in-memory processing.
- Harder to write and debug than declarative SQL.

#### Example: Count Shark Sightings per Month
- MongoDB MapReduce:
  ```javascript
  db.observations.mapReduce(
    function map() {
      var year = this.observationTimestamp.getFullYear();
      var month = this.observationTimestamp.getMonth() + 1;
      emit(year + "-" + month, this.numAnimals);
    },
    function reduce(key, values) {
      return Array.sum(values);
    },
    {
      query: { family: "Sharks" },
      out: "monthlySharkReport"
    }
  );
  ```
- MongoDB Aggregation Pipeline (more declarative):
  ```javascript
  db.observations.aggregate([
    { $match: { family: "Sharks" } },
    { $group: {
        _id: {
          year: { $year: "$observationTimestamp" },
          month: { $month: "$observationTimestamp" }
        },
        totalAnimals: { $sum: "$numAnimals" }
      }
    }
  ]);
  ```

---

## Graph-Like Data Models
- Best for highly interconnected data where anything can be related to anything.
- Examples: Social networks, web graph, road networks, fraud detection.
- Key insight: When relationships between data points are as important as the data itself.

### When to Use Graph Models
- Data has many **many-to-many** relationships.
- You need to traverse relationships (e.g., "friends of friends").
- Relationship types are diverse and evolving.
- Path queries are common (shortest path, reachability).

### Two Main Types of Graph Models
1. **Property Graph Model**: Neo4j, Amazon Neptune, OrientDB.
2. **Triple-Store Model (RDF)**: Datomic, AllegroGraph, Apache Jena.

### Property Graphs
- Each **vertex** (node) has:
  - Unique identifier.
  - Set of outgoing edges.
  - Set of incoming edges.
  - Collection of properties (key-value pairs).
- Each **edge** has:
  - Unique identifier.
  - Tail vertex (start).
  - Head vertex (end).
  - Label describing relationship.
  - Collection of properties.

#### Example: Relational Schema for Property Graph
```sql
CREATE TABLE vertices (
  vertex_id  INTEGER PRIMARY KEY,
  properties JSON
);

CREATE TABLE edges (
  edge_id     INTEGER PRIMARY KEY,
  tail_vertex INTEGER REFERENCES vertices(vertex_id),
  head_vertex INTEGER REFERENCES vertices(vertex_id),
  label       TEXT,
  properties  JSON
);

CREATE INDEX edges_tails ON edges(tail_vertex);
CREATE INDEX edges_heads ON edges(head_vertex);
```

#### Example: People and Locations Graph
- Vertices: Person (Lucy, Alain), Location (Idaho, USA, Europe, France).
- Edges: `born_in`, `lives_in`, `within`.
- Query: "Find all people who emigrated from US to Europe."

### Cypher Query Language
- Declarative query language for Neo4j (property graphs).
- ASCII-art syntax for expressing patterns: `(node)-[:RELATIONSHIP]->(node)`.
- Arrows indicate direction: `->` or `<-`.
- Variable-length paths: `[:WITHIN*0..]` means "follow zero or more WITHIN edges."

#### Key Cypher Concepts
- **MATCH**: Find patterns in the graph.
- **WHERE**: Filter results.
- **RETURN**: Specify what to output.
- **CREATE**: Add nodes and edges.
- Pattern matching is the core feature — describe what you're looking for, not how to find it.

#### Creating Data:
```cypher
CREATE
  (NAmerica:Location {name:'North America', type:'continent'}),
  (USA:Location {name:'United States', type:'country'}),
  (Idaho:Location {name:'Idaho', type:'state'}),
  (Lucy:Person {name:'Lucy'}),
  (Idaho) -[:WITHIN]-> (USA) -[:WITHIN]-> (NAmerica),
  (Lucy) -[:BORN_IN]-> (Idaho)
```

#### Querying: Find People Who Emigrated from US to Europe
```cypher
MATCH
  (person) -[:BORN_IN]-> () -[:WITHIN*0..]-> (us:Location {name:'United States'}),
  (person) -[:LIVES_IN]-> () -[:WITHIN*0..]-> (eu:Location {name:'Europe'})
RETURN person.name
```
- `[:WITHIN*0..]` means "follow zero or more WITHIN edges."

### Graph Queries in SQL
- Possible but cumbersome due to variable-length paths.
- Requires recursive common table expressions (CTEs).

#### Example: Same Query in SQL
```sql
WITH RECURSIVE
  in_usa(vertex_id) AS (
    SELECT vertex_id FROM vertices WHERE properties->>'name' = 'United States'
    UNION
    SELECT edges.tail_vertex FROM edges
      JOIN in_usa ON edges.head_vertex = in_usa.vertex_id
      WHERE edges.label = 'within'
  ),
  in_europe(vertex_id) AS (
    SELECT vertex_id FROM vertices WHERE properties->>'name' = 'Europe'
    UNION
    SELECT edges.tail_vertex FROM edges
      JOIN in_europe ON edges.head_vertex = in_europe.vertex_id
      WHERE edges.label = 'within'
  ),
  born_in_usa(vertex_id) AS (
    SELECT edges.tail_vertex FROM edges
      JOIN in_usa ON edges.head_vertex = in_usa.vertex_id
      WHERE edges.label = 'born_in'
  ),
  lives_in_europe(vertex_id) AS (
    SELECT edges.tail_vertex FROM edges
      JOIN in_europe ON edges.head_vertex = in_europe.vertex_id
      WHERE edges.label = 'lives_in'
  )
SELECT vertices.properties->>'name'
FROM vertices
  JOIN born_in_usa ON vertices.vertex_id = born_in_usa.vertex_id
  JOIN lives_in_europe ON vertices.vertex_id = lives_in_europe.vertex_id;
```
- 29 lines in SQL vs. 4 lines in Cypher!

### Triple-Stores and SPARQL

#### Triple-Store Model
- All information stored as three-part statements: **(subject, predicate, object)**.
- Example: `(Jim, likes, bananas)` → Jim likes bananas.
- Subject = vertex, Object = value or another vertex.
- Predicate = edge label (relationship) or property name.

#### How Triples Work
- If object is a **primitive value** (string, number): predicate is a property.
  - `(lucy, age, 33)` → Lucy's age is 33.
- If object is **another vertex**: predicate is an edge.
  - `(lucy, bornIn, idaho)` → Lucy was born in Idaho.

#### Semantic Web and RDF
- Triple-stores originated from the **Semantic Web** vision.
- RDF (Resource Description Framework): W3C standard for data interchange.
- Goal: Publish data in machine-readable format on the web.
- Reality: Overhyped in 2000s, but triple-stores remain useful for specific domains.
- Use cases: Knowledge graphs (Google, Wikidata), life sciences, linked data.

#### Turtle Format Example
```turtle
@prefix : <urn:example:>.
_:lucy     a       :Person;   :name "Lucy";          :bornIn _:idaho.
_:idaho    a       :Location; :name "Idaho";         :type "state";   :within _:usa.
_:usa      a       :Location; :name "United States"; :type "country"; :within _:namerica.
_:namerica a       :Location; :name "North America"; :type "continent".
```

#### SPARQL Query Language
- Query language for RDF triple-stores (like Cypher for property graphs).

```sparql
PREFIX : <urn:example:>
SELECT ?personName WHERE {
  ?person :name ?personName.
  ?person :bornIn / :within* / :name "United States".
  ?person :livesIn / :within* / :name "Europe".
}
```

### Datalog
- Older query language (1980s), foundation for later query languages.
- Uses **facts** and **rules**.
- Data defined as `predicate(subject, object)`.
- Key feature: **Recursive rules** — define complex queries by building on simpler ones.

#### How Datalog Differs
- Instead of one big query, you define small **rules** that build on each other.
- Rules can reference other rules (and themselves) → recursion.
- Query engine figures out which rules to apply and in what order.
- Think of it as defining "views" that can reference other "views."

#### Why Datalog Matters
- Foundation for Prolog and logic programming.
- Influenced SPARQL and Cypher.
- Used in Datomic (Clojure database), LogicBlox, and academic research.
- Excellent for expressing recursive queries (e.g., graph traversals, ancestry).

#### Example: Define Data
```prolog
name(namerica, 'North America').
type(namerica, continent).
name(usa, 'United States').
type(usa, country).
within(usa, namerica).
name(idaho, 'Idaho').
type(idaho, state).
within(idaho, usa).
name(lucy, 'Lucy').
born_in(lucy, idaho).
```

#### Example: Query with Rules
```prolog
within_recursive(Location, Name) :- name(Location, Name).
within_recursive(Location, Name) :- within(Location, Via), within_recursive(Via, Name).

migrated(Name, BornIn, LivingIn) :-
  name(Person, Name),
  born_in(Person, BornLoc),
  within_recursive(BornLoc, BornIn),
  lives_in(Person, LivingLoc),
  within_recursive(LivingLoc, LivingIn).

?- migrated(Who, 'United States', 'Europe').
/* Returns: Who = 'Lucy' */
```

---

## Summary

| Data Model | Best For | Query Language | Examples |
|------------|----------|----------------|----------|
| Relational | Structured data, many-to-many relationships | SQL | PostgreSQL, MySQL, Oracle |
| Document | Self-contained documents, one-to-many | MongoDB Query, Aggregation | MongoDB, CouchDB, RethinkDB |
| Graph | Highly interconnected data | Cypher, SPARQL, Gremlin | Neo4j, Amazon Neptune, Dgraph |

### Key Takeaways
1. **Relational model**: Best for structured data with complex relationships and transactions.
2. **Document model**: Best for self-contained records with tree-like structure.
3. **Graph model**: Best when relationships between entities are as important as the entities themselves.
4. **Query languages**: Declarative (SQL, Cypher, SPARQL) preferred over imperative for databases.
5. **No one-size-fits-all**: Choose based on your data's structure and access patterns.
6. **Convergence**: Modern databases often support multiple models (polyglot persistence).