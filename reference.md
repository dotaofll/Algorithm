Bibliography  : reference.bib

# Title

## Zero-shot references

### MNMT improve translation performance in low-resource settings

[1] need to proceed!
@koehn2017six

[2]&[3] target-forcing tech which is to perpend to the source sentence a tag specifying the target language,both training and testing time
@johnson2017google,@ha2016toward

[4] recent experiments have shown that the mechanism fails to achieve reasonable zero-shot translation performance for low-resource languages.
@sennrich2015improving

    ZST 从Fir(2016a)开始进入视野。然后基本上都说一说优缺点，然后就过了

[5] zero-resource NMT has been suggested
@firat2016zero

### A Teacher-Student Framework for Zero-Resource Neural Machine Translation

[6]&[7] NMT has achieved state-of-art translation performance on resource-rich language pairs such as English-French and German-English.
@luong2014addressing,@jean2014using

[8] GNMT
@wu2016google

[9] 这同时也开创了zero-shot translation的大规模落地用法。
@johnson2017google

[7] this paper indicate that NMT obtains much worse translation quality than a statistical machine translation system on low-resource languages.
@zoph2016transfer

[8] To enable zero-shot translation there are two broad categories: multilingual & pivot-based
Firat et al.,(2016b) present a multi-way,multilingual model with shared attention to achieve zero-resource translation.More detail they fine-tune the attention part using pseudo bilingual sentences for the zero-resource language pair.
@firat2016multi

Another direction is to develop a universal NMT model in multilingual scenarios.

They use parallel corpora of multiple languages to train one single model,which is then able to translate a language pair without parallel corpora available.

@johnson2017google

[9] Another direction is to achieve source-to-target NMT without parallel data via a pivot

it first translates the source language to a pivot language,which is then translated to the target language.

@cheng2016neural

[10] error propagation and computationally expensive

@zhu2013improving

### A Comparison of Transformer and Recurrent Neural Networks on Multilingual Neural Machine Translation

[11] As witnessed by recent machine translation evaluation campaigns 

@cettolo2017overview

[12] there have also been attempts to incorporate multiple languages in the source

@luong2014addressing,@zoph2016transfer

and in the target,
@dong2015multi

or in the both
@firat2016multi

[13] it relies on single "universal" encoder,decoder and attention modules,and manages multilinguality by introducing an artificial token at the beginning of the input sentence to specify
the requested target language

@johnson2017google,@ha2016toward

[14] the current NMT state-of-the-art includes the use of rnn,initially introduced in
@sutskever2014sequence

cnn,proposed by 
@gehring2017convolutional

and so-called transformer neural networks,recently proposed by 
@vaswani2017attention

The Transformer approach delivers the best performing multilingual models,with a larger gain over
corresponding bilingual models than observed with RNNs

The Transformer model delivers the best quality in all considered zero-shot condition and translation
directions
@lakew2018comparison

### Improved Zero-shot Neural Machine Translation via Ignoring Spurious Correlations

[15] Despite the recent domination of neural network-based models
in the field of machine translation,which have fewer pipelined components and significantly
outperform phrase-based systems, Neural Machine Translation (NMT) still works poorly when
the available number of training examples is limited.
@koehn2003statistical

[16] In this work, we start with a typical degeneracy issue of zero-shot NMT, reported in several recent works
that zero-shot NMT is sensitive to training conditions, and the translation
quality usually lags behind the pivot-based methods which use a shared language as a bridge for
translation
@arivazhagan2019missing,@sestorain2018zero

### Translationese as a Language in “Multilingual” NMT

[17] human raters prefer MT output that
is closer in distribution to original target text than
translationese
@freitag2019ape

### Google’s Neural Machine Translation System: Bridging the Gap between Human and Machine Translation

[18] The strength of NMT
lies in its ability to learn directly, in an end-to-end fashion, the mapping from input text to associated
output text.
@sutskever2014sequence

[19] An advantage of Neural Machine Translation is that it sidesteps many brittle design choices in traditional
phrase-based machine translation.
@koehn2003statistical

[20] NMT systems sometimes produce output sentences that do not translate all
parts of the input sentence – in other words, they fail to completely “cover” the input, which can result in
surprising translations
@wu2016google

[21] NMT translation quality has crept closer to
the level of phrase-based translation systems for common research benchmarks. Perhaps the first successful
attempt at surpassing phrase-based translation was described in
@luong2014addressing

[22] since then,many novel techniques have been proposed to further improve NMT: using an attention
mechanism to deal with rare words
@jean2014using

[24] multi-task and
semi-supervised training to incorporate more data.
@dong2015multi

[25] different kinds of attention mechanisms
@luong2015effective

### Meta-Learning for Low-Resource Neural Machine Translation

[26] In general,there are two ways for
handling the problem of low resource translation:
(1) utilizing the resource of unlabeled monolingual data, and (2) sharing the knowledge between
low- and high-resource language pairs

 Many research efforts have been spent on incorporating
the monolingual corpora into machine translation,
such as multi-task learning
@gulcehre2015using

unsupervised machine translation with monolingual corpora only for both sides.
@artetxe2017unsupervised

[27] prior researches have
worked on methods to exploit the knowledge of
auxiliary translations, or even auxiliary tasks.
@cheng2016neural,@chen2017teacher

[28] A multilingual NMT system could improve the performance of low resource translation
by using a universal lexical representation to share
embedding information across languages
@gu2018universal

### A Meta-Learning Framework for Generalized Zero-Shot Learning

[29] For classification problems, one such challenging setting is where test-time requires correctly labeling objects
that could be from classes that were not present at training time. This setting is popularly known as Zero-Shot
Learning (ZSL), and has drawn a considerable interest recently
@verma2017simple,@norouzi2013zero,@socher2013zero

### Cross-Lingual Natural Language Generation via Pre-Training

[30] Various methods have been proposed over the years to
learn cross-lingual word embeddings
@mikolov2013exploiting,@xing2015normalized,@conneau2018xnli

[31] sentence encoders which try to encode multilingual texts into a shared vector space.
@johnson2017google,@conneau2018xnli,@lample2019cross

### Zero-Shot Cross-Lingual Transfer with Meta Learning

[32] There are more than 7 000 languages spoken in the
world, over 90 of which have more than 10 million native speakers each.
@simons2017ethnologue

