---
layout: page
title: Home
permalink: /
order: 100
navigation: false
---

{% assign sessions = site.sessions | sort: 'name' %}
{% for session in sessions %}
{% if session.draft %}{% continue %}{% endif %}

---

<div class="container">
  <h2>{{ session.name }}
  <small>
  {% for date in session.dates %}
  {% assign section = forloop.index | prepend: '000' | slice: -3, 3 %}
  <span class="section-{{ section }}">({{ section }}: {{ date | date_to_string }})</span>
  {% endfor %}
  </small>
  </h2>

  <h3><em>{{ session.title }}</em></h3>

  <h4>Class Material</h4>
  <ul>
    <li><a href="{{ site.baseurl }}{{ session.url }}">Outline</a></li>
    <li><a href="{{ site.repo_url }}/tree/master/{{ session.name | replace: ' ', '_'}}">Code</a></li>
  </ul>

  {% assign assignments = site.assignments | where: "assigned", session.name %}
  {% if assignments.size != 0 %}
  <h4>Assignments</h4>
  <ul>
  {% for assignment in assignments %}
    <li><a href="{{ site.baseurl }}{{ assignment.url }}">{{ assignment.title }}</a></li>
  {% endfor %}
  </li>
  {% endif %}

  {% assign assignments = site.assignments | where: "due", session.name %}
  {% if assignments.size != 0 %}
  <h4>Due</h4>
  <ul>
  {% for assignment in assignments %}
    <li><a href="{{ site.baseurl }}{{ assignment.url }}">{{ assignment.title }}</a></li>
  {% endfor %}
  <ul>
  {% endif %}

  {% assign notes = site.notes | where: "session", session.name %}
  {% if notes.size != 0 %}
  <h4>Notes</h4>
  <ul>
  {% for note in notes %}
    <li><a href="{{ site.baseurl }}{{ note.url }}">{{ note.title }}</a></li>
  {% endfor %}
  </ul>
  {% endif %}

  {% assign notes = site.notes | where: "session", session.name %}
  {% if notes.size != 0 %}
  <h4>Notes</h4>
  <ul>
  {% for note in notes %}
    <li><a href="{{ site.baseurl }}{{ note.url }}">{{ note.title }}</a></li>
  {% endfor %}
  </ul>
  {% endif %}
</div>
{% endfor %}
