streams-sourceop-twitter
========================

InfoSphere Streams Java primitive source operator for Twitter's streaming APIs

This project is an implementation of a Java primitive operator for IBM InfoSphere Streams to be able to use Twitter's streaming API as a source for a Streams application. Once such a source is defined, you could optionally make use of various analytical operators such as the Text Analytics toolkit to extract some kind of useful insights from this information.

The modifications steps necessary to reproduce this on your own environment are as follows:
- set up an application on https://dev.twitter.com/ for the The Streaming APIs
- copy the application API keys to the Java code. They are used to authenticate requests to the Twitter Platform.
  -   private final static String CONSUMER_KEY = "";
  -   private final static String CONSUMER_SECRET = "";
  -   private final static String ACCESS_TOKEN = "";
  -   private final static String ACCESS_SECRET = "";
- add the following libraries from Twitter to your project:
  -   twitter4j-async-4.0.1.jar
  -   twitter4j-core-4.0.1.jar
  -   twitter4j-stream-4.0.1.jar
- config library paths and any necessary input params in TwitterSource.xml
- change search criteria sent to Twitter in the TwitterSource() operator in twitterdemo.spl
