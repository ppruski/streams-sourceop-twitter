streams-sourceop-twitter
========================

InfoSphere Streams Java primitive source operator for Twitter's streaming APIs

Modifications necessary:
- set up an application on dev.twitter for the The Streaming APIs
- copy the application API keys to the Java code. They are used to authenticate requests to the Twitter Platform.
  -   private final static String CONSUMER_KEY = "";
  -   private final static String CONSUMER_SECRET = "";
  -   private final static String ACCESS_TOKEN = "";
  -   private final static String ACCESS_SECRET = "";
- add the following libraries from twitter to your project:
  -   twitter4j-async-4.0.1.jar
  -   twitter4j-core-4.0.1.jar
  -   twitter4j-stream-4.0.1.jar
- config library paths and any necessary input params in TwitterSource.xml
