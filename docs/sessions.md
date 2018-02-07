---
layout: page
title: Sessions
permalink: /sessions
navigation: false
---

<!-- {% for collection in site.collections %}


<ul>
{% if collection.name and collection.docs.size != 0 %}
{% for doc in collection.docs %}
<a class="dropdown-item" href="{{ site.baseurl }}{{ doc.url }}">{{ doc.title }}</a>
{% endfor %}

    <li><a href="{{ site.baseurl }}{{ doc.url }}">{{ collection.name }} - {{ doc.title }}</a></li>
{% endif %}
</ul>
{% endfor %} -->



{% assign sessions = site.sessions | sort: 'name' %}

{% for session in sessions %}
<hr>
<div class="container">
  ## {{ session.name }} <small>{% for date in session.dates %}{% assign section = forloop.index | prepend: '000' | slice: -3, 3 %}({{ section }}: {{ date | date_to_string }}){% endfor %}</small>
  -   {{ session.title }}

  <h2>{{ session.name }}
  <small>
  {% for date in session.dates %}
  {% assign section = forloop.index | prepend: '000' | slice: -3, 3 %}
  <span class="section-{{ section }}">({{ section }}: {{ date | date_to_string }})</span>
  {% endfor %}
  </small>
  </h2>

  {% assign assignments = site.assignments | where: "assigned", session.name %}
  <h4>Assignments</h4>
  {% if assignments.size != 0 %}
  {% for assignment in assignments %}
  <a href="{{ site.baseurl }}{{ assignment.url }}">{{ assignment.title }}</a>
  {% endfor %}
  {% else %}
  <em>None</em>
  {% endif %}

  <h4>Due</h4>
  {% assign assignments = site.assignments | where: "due", session.name %}
  {% if assignments.size != 0 %}
  {% for assignment in assignments %}
  <a href="{{ site.baseurl }}{{ assignment.url }}">{{ assignment.title }}</a>
  {% endfor %}
  {% else %}
  <em>None</em>
  {% endif %}

  <h4>Notes</h4>
  {% assign notes = site.notes | where: "session", session.name %}
  {% if notes.size != 0 %}
  {% for note in notes %}
  <a href="{{ site.baseurl }}{{ note.url }}">{{ note.title }}</a>
  {% endfor %}
  {% else %}
  <em>None</em>
  {% endif %}
</div>
{% endfor %}
