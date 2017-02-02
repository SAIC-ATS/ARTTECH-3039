---
layout: page
title: Assignments
permalink: /assignments/
order: 200
---

<ul class="list-unstyled">
    {% for post in site.categories.assignment %}
    <li>
        {{ post.date | date_to_string }} :
        <a href="{{ site.baseurl }}{{ post.url }}">{{ post.title }}</a>
        <small>Due: {{ post.due }}</small>
    </li>
    {% endfor %}
</ul>
