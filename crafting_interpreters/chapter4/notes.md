# Chapter 4: Scanning

## Lexemes and Tokens

eg. var language = "lox";
Scan through list of characters and group them together into the smallest sequence that represents something. Each of these blobs of characters is called *"lexeme"*.
In the above sentence, lexemes are (var), (language), (=), ("lox"), (;)
Take lexeme and bundle it together with other data => Result is token
language is a lexeme for token "identifier"
"lox" is a lexeme for token literal.

Token: A group of characters having collective meaning: typically a word or punctuation mark, separated by a lexical analyzer and passed to a parser.

Lexeme: An actual character sequence forming a specific instance of a token such as *var*

Pattern: A rule that describes the set of strings associated to a token. Expressed as a regular expression and describing how a particular token can be formed.
For example, \[A-Za-z\]\[A-Za-z_0-9\]\*

The parser could categorize tokens from the raw lexeme by comparing the strings, but that’s slow and kind of ugly. Instead, at the point that we recognize a lexeme, we also remember which kind of lexeme it represent.s
The rules that determine how a particular language groups characters into lexemes are called its lexical grammar.
